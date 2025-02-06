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
    	// Initialisation ODBC
    	ODBC::Connector::registerConnector();

    	// Connexion à la base via le DSN
    	Session session("ODBC", "DSN=Projet_Ventilation_ERP");

    	int valeur = 0;
    	Statement select(session);
	// Requête SQL
    	select << "SELECT puissance_demandee_pourcentage FROM zone ORDER BY module_id DESC LIMIT 1;",

		// Into pour stocker le résultat de la requête dans la variable et now pour l'exécuter
           	into(valeur), now;

    	cout << "Dernière valeur : " << valeur << "%" << endl;
	}
	catch (const Poco::Exception& ex) {
    	cerr << "Erreur ODBC : " << ex.displayText() << endl;
    	return 1;
	}

	return 0;
}
