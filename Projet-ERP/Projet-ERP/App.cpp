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
/**
 * @brief Méthode qui permet d'ajouter un topic à s'abonner, ce que subscribe() fera
 * 
 * @param topic			Nom du topic auquel il faut s'abonner
 */

bool App::OnInit(){
	wxCmdLineParser parser(wxAppConsole::argc, wxAppConsole::argv);
	if(!DoParseCommandLine(parser)){
		return false;
	}

	AccesDonneesCapteurs capteurs;
	double temperature, hygrometrie, co2;
	int module;
	time_t date;

	//Test communication avec la classe AccesDonneesCapteurs + subscribe Mqtt
	if (capteurs.enregistrerQualiteAir(module, date, temperature, hygrometrie, co2)) {
		std::cout<<"Lecture des capteurs réussie: "<<std::endl
				 <<"Module: "<<module <<std::endl
				 <<"Date: "<<std::asctime(std::localtime(&date))<<std::endl
				 <<"Température: "<<temperature<<"°C"<<std::endl
				 <<"Hygrométrie: "<<hygrometrie<<"%"<<std::endl
				 <<"CO2: "<<co2<<"ppm"<<std::endl
				 <<"La qualité de l'air est : "<<capteurs.computeQualiteAir(co2)<<std::endl;
		
		//Topic à subscribe pour les données uniquement
		//capteurs.pushbackTopic("ventilation/+/capteurs");
		
		//Topic à subscribe pour les données + infos tasmota
		capteurs.pushbackTopic("ventilation/+/capteurs/#");
		
		cout << "Veuillez entrer q ou quit pour quitter" << endl;
		std::string in;
		do {
		std::cin >> in;
		}while (in != "q" && in != "quit" && in != "Q" && in != "QUIT");
		exit(0);
	}
	else {
		std::cerr << "Erreur de lecture des capteurs"<<std::endl;
	}
    return true;
}

/**
 * @brief Méthode qui permet de lire les paramètres 
 * 
 * @param topic			Nom du topic auquel il faut s'abonner
 */

bool App::DoParseCommandLine(wxCmdLineParser& parser){
    wxUnusedVar(parser);
    return true;
}