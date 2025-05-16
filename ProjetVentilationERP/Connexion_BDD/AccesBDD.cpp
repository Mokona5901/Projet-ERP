/****************************************************************************
 *  Fichier:  AccesBDD.cpp
 *  Projet:   ProjetERP
 *  Crée le:  14/05/2025
 * 	Version:  1.0
 *  Utilité:  Permet l'accès à la BdD ProjetERP
 *  Auteur:   Sofiane El Bouhali
 ****************************************************************************/
#include <iostream>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Exception.h>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;
using namespace std;

int main() {
    try {
        // Enregistrement du connecteur ODBC
        ODBC::Connector::registerConnector();

        // Connexion à la base via le DSN
        Session session("ODBC", "DSN=ProjetERP");

        int valeur = 0;
        Statement select(session);
        select << "SELECT puissance_demandee FROM zone ORDER BY id_zone DESC LIMIT 1",
               into(valeur), now;

        cout << "Dernière valeur : " << valeur << "%" << endl;
    }
    catch (const Poco::Exception& ex) {
        cerr << "Erreur ODBC : " << ex.displayText() << endl;
        return 1;
    }

    return 0;
}
