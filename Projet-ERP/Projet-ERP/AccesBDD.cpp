/**
 * @file AccesBDD.cpp
 * @author Enzo Flament
 * @brief Implémentation de la classe AccesBDD
 * @version 1.1
 * @date 15-06-2025
 */

#include "AccesBDD.h"
#include <iostream>
#include <sstream>

AccesBDD::AccesBDD(string dsn) {
    m_session=NULL;
    m_connexionOK=true;
    ODBC::Connector::registerConnector();
    try
    {
        m_session= new Session("ODBC", "DSN="+dsn);
    }
    catch (ConnectionFailedException& ce)
    {
        m_last_error= ce.displayText();
        m_connexionOK=false;
    }
}

AccesBDD::~AccesBDD() {
   if (m_session) delete m_session;
}

bool AccesBDD::ExecuteSelect(string requete) {
    bool retour=true;
    if (m_session != NULL) {
        try {
            Statement select(*m_session);
            select << requete;
            RecordSet rs(select);
            
            select.execute();
            bool more = rs.moveFirst();
            m_last_result.clear();
            m_nombreColonnesResultat=rs.columnCount();
            
            while (more)
            {
                for (std::size_t col = 0; col < m_nombreColonnesResultat; ++col){
                    m_last_result.push_back(rs[col].convert<string>());
                }
                more = rs.moveNext();
            }
        }            
        catch (ODBC::StatementException& se) {
            m_last_error= se.toString();
            retour=false;
        }
    }
    return retour;
}

int AccesBDD::GetPuissanceDemandee(int &id_module) {
    std::ostringstream oss;
    oss << "SELECT puissance_demandee_pourcentage FROM zone WHERE module_id = " << id_module << ";";
    std::string result = oss.str();
    ExecuteSelect(result);
    int puissance_demandee = 0;
    if (!m_last_result.empty()) {
        puissance_demandee = std::stoi(m_last_result[0]);
    }
    return puissance_demandee;
}

bool AccesBDD::SetPuissanceDemandee(int &id_module, int &puissance_demandee, time_t &date) {

    std::ostringstream oss;
    oss << "UPDATE zone SET puissance_demandee_pourcentage = " << puissance_demandee 
        << " WHERE module_id = " << id_module << ";";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    return retour;
}

float AccesBDD::GetQualite(int &module) {
    std::ostringstream oss;
    oss << "SELECT qualite_air FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    ExecuteSelect(result);
    float qualite_air = 0;
    if (!m_last_result.empty()) {
        qualite_air = std::stof(m_last_result[0]);
    }
    return qualite_air;
}

double AccesBDD::GetTemperature(int &module) {
    std::ostringstream oss;
    oss << "SELECT temperature FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    ExecuteSelect(result);
    double temperature = 0;
    if (!m_last_result.empty()) {
        temperature = std::stod(m_last_result[0]);
    }
    return temperature;
}

double AccesBDD::GetHygrometrie(int &module) {
    std::ostringstream oss;
    oss << "SELECT hygrometrie FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    ExecuteSelect(result);
    double hygrometrie = 0;
    if (!m_last_result.empty()) {
        hygrometrie = std::stod(m_last_result[0]);
    }
    return hygrometrie;
}

double AccesBDD::GetCO2(int &module) {
    std::ostringstream oss;
    oss << "SELECT co2 FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    ExecuteSelect(result);
    double co2 = 0;
    if (!m_last_result.empty()) {
        co2 = std::stod(m_last_result[0]);
    }
    return co2;
}

bool AccesBDD::SetCapteurs(double &temperature, double &hygrometrie, double &co2, float &qualite_air, int &module, time_t &date) {
    std::ostringstream oss;
    oss << "INSERT INTO mesure_qualite_air (module_id, temperature, hygrometrie, co2, qualite_air, date) VALUES ("
        << module << ", " << temperature << ", " << hygrometrie << ", " << co2 << ", " 
        << qualite_air << ", NOW());";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    return retour;
}

double AccesBDD::GetDebit(int &id_module_ventilation) {  
    std::ostringstream oss;
    oss << "SELECT debit_air FROM mesure_ventilation WHERE module_id = " << id_module_ventilation 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    ExecuteSelect(result);
    double debit_air = 0;
    if (!m_last_result.empty()) {
        debit_air = std::stod(m_last_result[0]);
    }
    return debit_air;
}

bool AccesBDD::SetDebit(int &id_module_ventilation, double &debit_air, time_t &date) {
    std::ostringstream oss;
    oss << "INSERT INTO mesure_ventilation (module_id, debit_air, date) VALUES ("
        << id_module_ventilation << ", " << debit_air << ", NOW());";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);  
    return retour;
}

int AccesBDD::GetPuissanceActuelle(int &id_module_ventilation) {
    std::ostringstream oss;
    oss << "SELECT puissance_actuelle_pourcentage FROM zone WHERE module_id = " << id_module_ventilation << ";";
    std::string result = oss.str();
    ExecuteSelect(result);
    int puissance_actuelle = 0;
    if (!m_last_result.empty()) {
        puissance_actuelle = std::stoi(m_last_result[0]);
    }
    return puissance_actuelle;
}

bool AccesBDD::SetPuissanceActuelle(int &id_module_ventilation, int &puissance_actuelle, time_t &date) {
    std::ostringstream oss;
    oss << "UPDATE zone SET puissance_actuelle_pourcentage = " << puissance_actuelle 
        << " WHERE module_id = " << id_module_ventilation << ";";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    return retour;
}

std::string AccesBDD::GetNomZone() {
    std::ostringstream oss;
    oss << "SELECT nom FROM zone;";
    std::string result = oss.str();
    ExecuteSelect(result);
    std::string nom_zone = " ";
    if (!m_last_result.empty()) {
        nom_zone = m_last_result[0];
    }
    return nom_zone;
}