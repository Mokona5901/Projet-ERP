#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Exception.h>
#include <pigpio.h>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <module_id> <puissance_demandee_initiale>\n";
        return 1;
    }

    int module_id = std::atoi(argv[1]);
    int puissance_demandee = std::atoi(argv[2]);

    if (puissance_demandee < 0 || puissance_demandee > 100) {
        std::cerr << "Valeur invalide. Doit être entre 0 et 100.\n";
        return 1;
    }

    if (gpioInitialise() < 0) {
        std::cerr << "Erreur d'initialisation de pigpio.\n";
        return 1;
    }

    const int gpioPin = 18;
    const int freq = 1000;
    gpioSetMode(gpioPin, PI_OUTPUT);
    gpioSetPWMfrequency(gpioPin, freq);

    try {
        Poco::Data::ODBC::Connector::registerConnector();
        Session session("ODBC", "DSN=Projet_Ventilation_ERP");

        while (true) {
            int puissance_actuelle = 0;
            bool found = false;

            Statement select(session);
            select << "SELECT puissance_actuelle_pourcentage FROM zone WHERE module_id = ?",
                   use(module_id), into(puissance_actuelle), now;
            found = !select.done() || select.rowsExtracted() > 0;

            if (!found || puissance_actuelle < 0 || puissance_actuelle > 100) {
                std::cerr << "Erreur : puissance_actuelle invalide ou non trouvée en BDD.\n";
                break;
            }

            if (puissance_actuelle == puissance_demandee) {
                std::cout << "La puissance demandée est déjà appliquée (" << puissance_demandee << "%). Rien à faire.\n";
            } else {
                std::cout << "Ancienne puissance actuelle : " << puissance_actuelle << "%\n";
                std::cout << "Nouvelle puissance demandée : " << puissance_demandee << "%\n";

                int rapport = (puissance_demandee * 255) / 100;
                gpioPWM(gpioPin, rapport);

                Statement updateDemande(session);
                updateDemande << "UPDATE zone SET puissance_demandee_pourcentage = ? WHERE module_id = ?",
                              use(puissance_demandee), use(module_id), now;

                std::this_thread::sleep_for(std::chrono::seconds(10));

                std::time_t timestamp = std::time(nullptr);
                Statement update(session);
                update << "UPDATE zone SET puissance_actuelle_pourcentage = ?, puissance_demandee_pourcentage = ?, date = to_timestamp(?)::timestamp(0) "
                       "WHERE module_id = ?",
                       use(puissance_demandee), use(puissance_demandee), use(timestamp), use(module_id), now;

                std::cout << "Mise à jour BDD effectuée. La puissance actuelle est maintenant " << puissance_demandee << "%.\n";
            }

            std::string saisie;
            std::cout << "Entrer une nouvelle puissance (0–100) ou 'q' pour quitter : ";
            std::cin >> saisie;

            if (saisie == "q" || saisie == "Q") {
                std::time_t timestamp = std::time(nullptr);
                gpioPWM(gpioPin, 0);

                Statement reset(session);
                reset << "UPDATE zone SET puissance_actuelle_pourcentage = 0, puissance_demandee_pourcentage = 0, date = to_timestamp(?)::timestamp(0) "
                      "WHERE module_id = ?",
                      use(timestamp), use(module_id), now;

                std::cout << "Arrêt demandé. PWM coupé et BDD remise à 0.\n";
                break;
            }

            try {
                size_t pos = 0;
                int temp = std::stoi(saisie, &pos);
                if (pos != saisie.length() || temp < 0 || temp > 100) {
                    throw std::invalid_argument("Valeur invalide.");
                }
                puissance_demandee = temp;
            } catch (...) {
                std::cerr << "Entrée invalide. Tapez un nombre entre 0 et 100 ou 'q'.\n";
                continue;
            }
        }
    } catch (const Poco::Exception& ex) {
        std::cerr << "Erreur ODBC : " << ex.displayText() << '\n';
        gpioPWM(gpioPin, 0);
        gpioTerminate();
        return 1;
    }

    gpioPWM(gpioPin, 0);
    gpioTerminate();
    return 0;
}

