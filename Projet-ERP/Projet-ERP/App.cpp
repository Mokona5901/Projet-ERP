/**
 * @file App.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe App
 * @version 1.0
 * @date 18-05-2025
 */

#include "App.h"
#include "BDD.h"

IMPLEMENT_APP_CONSOLE(App)

App::App(){
	
}

App::~App(){
	
}

int App::OnExit(){
	return true;
}

bool App::OnInit(){
	wxCmdLineParser parser(wxAppConsole::argc, wxAppConsole::argv);
	if(!DoParseCommandLine(parser)){
		return false;
	}

	// Initialization code here
	AccesDonneesCapteurs capteurs;
	double temperature, hygrometrie, co2;
	int module;
	time_t date;
	
	//Database test code
	/*std::string dsn = "ProjetERP";
    BDD db(dsn);

    if (!db.IsConnexionOK()) {
        std::cerr << "Erreur de connexion : " << db.GetLastError() << std::endl;
        return 1;
    }

    std::string requete = "SELECT * FROM mesure_qualite_air LIMIT 5";

    if (!db.ExecuteSelect(requete)) {
        std::cerr << "Erreur d'exécution de la requête : " << db.GetLastError() << std::endl;
        return 1;
    }

    auto result = db.GetLastResult();
    unsigned int nbCols = db.GetNombreColonnesResultat();

    std::cout << "Résultats de la requête :" << std::endl;

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << "\t";

        if ((i + 1) % nbCols == 0) std::cout << std::endl;
    }*/

	//test communication avec la classe AccesDonneesCapteurs + subscribe Mqtt
	if (capteurs.enregistrerQualiteAir(module, date, temperature, hygrometrie, co2)) {
		std::cout<<"Lecture des capteurs réussie: "<<std::endl;
		std::cout<<"Module: "<<module <<std::endl;
		std::cout<<"Date: "<<std::asctime(std::localtime(&date))<<std::endl;
		std::cout<<"Température: "<<temperature<<"°C"<<std::endl;
		std::cout<<"Hygrométrie: "<<hygrometrie<<"%"<<std::endl;
		std::cout<<"CO2: "<<co2<<"ppm"<<std::endl;
		std::cout<<"La qualité de l'air est : "<<capteurs.computeQualiteAir(module, co2, date)<<std::endl;
		capteurs.pushbackTopic("ventilation/groupe1/#");
		cout << "type quit or q to quit" << endl;
		std::string in;
		do {
		std::cin >> in;
		}while (in != "quit" && in != "q");
		exit(0);
	}
	else {
		std::cerr << "Erreur de lecture des capteurs"<<std::endl;
	}
    return true;
}

bool App::DoParseCommandLine(wxCmdLineParser& parser){
    wxUnusedVar(parser);
    return true;
}