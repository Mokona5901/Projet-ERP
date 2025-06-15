/**
 * @file AccesBDD.h
 * @author Enzo Flament
 * @brief Declaration de la classe AccesBDD
 * @version 1.1
 * @date 15-06-2025
 */

#ifndef AccesBDD_H
#define AccesBDD_H

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

class AccesBDD  
{
    public:
        AccesBDD(string dsn);
        ~AccesBDD();
        bool IsConnexionOK(){return m_connexionOK;};
        string GetLastError(){return m_last_error;};
        vector<string> GetLastResult(){return m_last_result;};
        unsigned int GetNombreColonnesResultat(){return m_nombreColonnesResultat;};
        bool ExecuteSelect(string requete);

        int GetPuissanceDemandee(int &id_module);
        bool SetPuissanceDemandee(int &id_module, int &puissance_demandee, time_t &date);
        float GetQualite(int &module); 
        double GetTemperature(int &module);
        double GetHygrometrie(int &module);
        double GetCO2(int &module);
        bool SetCapteurs(double &temperature, double &hygrometrie, double &co2, float &qualite_air, int &module, time_t &date);
        double GetDebit(int &id_module_ventilation);
        bool SetDebit(int &id_module_ventilation, double &debit_air, time_t &date);
        int GetPuissanceActuelle(int &id_module_ventilation);
        bool SetPuissanceActuelle(int &id_module_ventilation, int &puissance_actuelle, time_t &date);
		std::string GetNomZone();

    protected:
    private:
        Session *m_session;
        bool m_connexionOK;
        string m_last_error;
        vector<string> m_last_result;
        unsigned int m_nombreColonnesResultat;
};

#endif // AccesBDD_H