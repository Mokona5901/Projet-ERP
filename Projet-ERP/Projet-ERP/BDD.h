/**
 * @file BDD.h
 * @author Enzo Flament
 * @brief Declaration de la classe BDD
 * @version 1.0
 * @date 03-06-2025
 */

#ifndef BDD_H
#define BDD_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
#include <ctime>
#include <Poco/Data/Session.h>
#include <Poco/Data/ODBC/Connector.h>
using namespace Poco::Data::ODBC;
using namespace Poco::Data;
#include <Poco/Exception.h>
#include "Poco/Data/ODBC/ODBCException.h"
#include <Poco/Data/RecordSet.h>

class BDD  // CORRECTION: c'était "ODBC" au lieu de "BDD"
{
    public:
        BDD(string dsn);  // CORRECTION: constructeur avec le bon nom
        ~BDD();
        bool IsConnexionOK(){return m_connexionOK;};
        string GetLastError(){return m_last_error;};
        vector<string> GetLastResult(){return m_last_result;};
        unsigned int GetNombreColonnesResultat(){return m_nombreColonnesResultat;};
        bool ExecuteSelect(string requete);

        bool GetPuissanceDemandee(int id_module, int puissance_demandee);
        bool SetPuissanceDemandee(int id_module, int puissance_demandee, time_t date);
        bool GetQualite(float qualite_air, int module); 
        bool GetTemperature(double temperature, int module);
        bool GetHygrometrie(double hygrometrie, int module);
        bool GetCO2(double co2, int module);
        bool SetCapteurs(double temperature, double hygrometrie, double co2, float qualite_air, int module, time_t date);
        bool GetDebit(int id_module_ventilation, double debit_air);
        bool SetDebit(int id_module_ventilation, double debit_air, time_t date);
        bool GetPuissanceActuelle(int id_module_ventilation, int puissance_actuelle);
        bool SetPuissanceActuelle(int id_module_ventilation, int puissance_actuelle, time_t date);

    protected:
    private:
        Session *m_session;
        bool m_connexionOK;
        string m_last_error;
        vector<string> m_last_result;
        unsigned int m_nombreColonnesResultat;
};

#endif // BDD_H