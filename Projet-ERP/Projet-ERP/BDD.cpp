/**
 * @file BDD.cpp
 * @author Enzo Flament
 * @brief Implémentation de la classe
 * @version 1.0
 * @date 03-06-2025
 */

#include "BDD.h"
#include <iostream>
#include <sstream>

BDD::BDD(string dsn) {
    m_session=NULL;
    m_connexionOK=true;
    // on va utiliser ODBC
    ODBC::Connector::registerConnector();
    // on essaye de se connecteur à la bdd avec les info contenues dans le dsn
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

BDD::~BDD() {
   if (m_session) delete m_session;  // CORRECTION: vérifier si non null
}

bool BDD::ExecuteSelect(string requete) {  // CORRECTION: ajout du type de retour
    bool retour=true;
    if (m_session != NULL) {
        try {
            Statement select(*m_session);
            select << requete;
            RecordSet rs(select);
            
            select.execute();  // CORRECTION: exécuter une seule fois
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

bool BDD::GetPuissanceDemandee(int id_module, int& puissance_demandee) {  // CORRECTION: référence pour récupérer la valeur
    std::ostringstream oss;
    oss << "SELECT puissance_demandee_pourcentage FROM zone WHERE module_id = " << id_module << ";";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        puissance_demandee = std::stoi(m_last_result[0]);
    }
    return retour;
}

bool BDD::SetPuissanceDemandee(int id_module, int puissance_demandee, time_t date) {
    // CORRECTION: utiliser ExecuteNonQuery pour UPDATE (à implémenter)
    std::ostringstream oss;
    oss << "UPDATE zone SET puissance_demandee_pourcentage = " << puissance_demandee 
        << " WHERE module_id = " << id_module << ";";
    std::string result = oss.str();
    
    // Note: Il faudrait implémenter ExecuteNonQuery pour les UPDATE/INSERT
    // Pour l'instant, on utilise ExecuteSelect mais ce n'est pas correct
    bool retour = ExecuteSelect(result);
    return retour;
}

bool BDD::GetQualite(float& qualite_air, int module) {  // CORRECTION: référence pour récupérer la valeur
    std::ostringstream oss;
    oss << "SELECT qualite_air FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        qualite_air = std::stof(m_last_result[0]);
    }
    return retour;
}

bool BDD::GetTemperature(double& temperature, int module) {  // CORRECTION: référence
    std::ostringstream oss;
    oss << "SELECT temperature FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        temperature = std::stod(m_last_result[0]);
    }
    return retour;
}

bool BDD::GetHygrometrie(double& hygrometrie, int module) {  // CORRECTION: référence
    std::ostringstream oss;
    oss << "SELECT hygrometrie FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        hygrometrie = std::stod(m_last_result[0]);
    }
    return retour;
}

bool BDD::GetCO2(double& co2, int module) {  // CORRECTION: référence
    std::ostringstream oss;
    oss << "SELECT co2 FROM mesure_qualite_air WHERE module_id = " << module 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        co2 = std::stod(m_last_result[0]);
    }
    return retour;
}

bool BDD::SetCapteurs(double temperature, double hygrometrie, double co2, float qualite_air, int module, time_t date) {
    std::ostringstream oss;
    oss << "INSERT INTO mesure_qualite_air (module_id, temperature, hygrometrie, co2, qualite_air, date) VALUES ("
        << module << ", " << temperature << ", " << hygrometrie << ", " << co2 << ", " 
        << qualite_air << ", NOW());";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);  // Note: devrait être ExecuteNonQuery
    return retour;
}

bool BDD::GetDebit(int id_module_ventilation, double& debit_air) {  // CORRECTION: référence
    std::ostringstream oss;
    oss << "SELECT debit_air FROM mesure_ventilation WHERE module_id = " << id_module_ventilation 
        << " ORDER BY date DESC LIMIT 1;";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        debit_air = std::stod(m_last_result[0]);
    }
    return retour;
}

bool BDD::SetDebit(int id_module_ventilation, double debit_air, time_t date) {
    std::ostringstream oss;
    oss << "INSERT INTO mesure_ventilation (module_id, debit_air, date) VALUES ("
        << id_module_ventilation << ", " << debit_air << ", NOW());";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);  // Note: devrait être ExecuteNonQuery
    return retour;
}

bool BDD::GetPuissanceActuelle(int id_module_ventilation, int& puissance_actuelle) {  // CORRECTION: référence
    std::ostringstream oss;
    oss << "SELECT puissance_actuelle_pourcentage FROM zone WHERE module_id = " << id_module_ventilation << ";";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);
    
    if (retour && !m_last_result.empty()) {
        puissance_actuelle = std::stoi(m_last_result[0]);
    }
    return retour;
}

bool BDD::SetPuissanceActuelle(int id_module_ventilation, int puissance_actuelle, time_t date) {
    std::ostringstream oss;
    oss << "UPDATE zone SET puissance_actuelle_pourcentage = " << puissance_actuelle 
        << " WHERE module_id = " << id_module_ventilation << ";";
    std::string result = oss.str();
    bool retour = ExecuteSelect(result);  // Note: devrait être ExecuteNonQuery
    return retour;
}