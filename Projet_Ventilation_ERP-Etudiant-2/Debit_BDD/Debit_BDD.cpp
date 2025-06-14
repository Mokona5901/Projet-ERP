#include <iostream>
#include <ctime>
#include <thread>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>

#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;

float simulateDebitAir()
{
    static std::default_random_engine engine(std::random_device{}());
    static std::uniform_real_distribution<float> dist(0.03f, 0.08f);
    return dist(engine);
}

int main()
{
    Poco::Data::ODBC::Connector::registerConnector();

    try {
        // Connexion via DSN configuré "Projet_Ventilation_ERP"
        Session session("ODBC", "DSN=Projet_Ventilation_ERP");

        std::cout << "Connexion établie. Insertion toutes les 10 secondes...\n";

        int module_id = 1;

        while (true) {
            float debit_air = std::round(simulateDebitAir() * 1000.0f) / 1000.0f;

            std::time_t timestamp = std::time(nullptr);

            Statement insert(session);
            insert << "INSERT INTO mesure_ventilation (module_id, debit_air, date) "
                      "VALUES (?, ?, to_timestamp(?))",
                      use(module_id), use(debit_air), use(timestamp);
            insert.execute();

            std::tm* tm = std::localtime(&timestamp);
            std::cout << "Débit inséré : " << std::fixed << std::setprecision(3)
                      << debit_air << " m³/s à "
                      << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << '\n';

            std::this_thread::sleep_for(std::chrono::seconds(10));
        }

    } catch (const std::exception& ex) {
        std::cerr << "Erreur : " << ex.what() << '\n';
        return 1;
    }

    return 0;
}

