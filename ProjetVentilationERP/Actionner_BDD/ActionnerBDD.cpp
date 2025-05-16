/****************************************************************************
 *  Fichier:  ActionnerBDD.cpp
 *  Projet:   ProjetERP
 *  Crée le:  14/05/2025
 * 	Version:  1.0
 *  Utilité:  Permet de faire sortir un signal PWM en récupérant la puissance demandée depuis la BdD
 *  Auteur:   Sofiane El Bouhali
 ****************************************************************************/
#include <iostream>
#include <pigpio.h>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Exception.h>

using namespace std;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

int main()
{
    if (gpioInitialise() < 0)
    {
        cerr << "Erreur pigpio\n";
        return 1;
    }

    try
    {
        // Initialisation ODBC
        ODBC::Connector::registerConnector();
        Session session("ODBC", "DSN=ProjetERP");

        // Récupération de la puissance
        int puissance = 0;
        Statement select(session);
        select << "SELECT puissance_demandee FROM zone ORDER BY id_zone DESC LIMIT 1", into(puissance), now;

        if (puissance < 1 || puissance > 100)
        {
            cerr << "Valeur de puissance invalide : " << puissance << "%\n";
            gpioTerminate();
            return 1;
        }

        // Configuration PWM
        int gpio = 18;
        int freq = 1000;
        int rapport = (puissance * 255) / 100;

        gpioSetMode(gpio, PI_OUTPUT);
        gpioSetPWMfrequency(gpio, freq);
        gpioPWM(gpio, rapport);

        cout << "PWM actif sur GPIO18 : " << puissance << "%.\n";
        cout << "Appuyez sur Entrée pour quitter\n";
        cin.get();

        gpioTerminate();
        return 0;
    }
    catch (const Poco::Exception& ex)
    {
        cerr << "Erreur ODBC : " << ex.displayText() << endl;
        gpioTerminate();
        return 1;
    }
}
