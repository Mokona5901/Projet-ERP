#include "App.h"

IMPLEMENT_APP_CONSOLE(App)

App::App(){
	
}

App::~App(){
	
}

int App::OnExit(){
	return TRUE;
}

bool App::OnInit(){
	wxCmdLineParser parser(wxAppConsole::argc, wxAppConsole::argv);
	if(!DoParseCommandLine(parser)){
		return false;
	}

	// Initialization code here
	AccesDonneesCapteurs capteurs;
	sleep(2);
	
	double temperature, hygrometrie, co2;
	int module;
	time_t date;
	if (capteurs.enregistrerQualiteAir(module, date, temperature, hygrometrie, co2)) {
		std::cout<<"Lecture des capteurs réussie: "<<std::endl;
		std::cout<<"Module: "<<module <<std::endl;
		std::cout<<"Date: "<<std::asctime(std::localtime(&date))<<std::endl;
		std::cout<<"Température: "<<temperature<<"°C"<<std::endl;
		std::cout<<"Hygrométrie: "<<hygrometrie<<"%"<<std::endl;
		std::cout<<"CO2: "<<co2<<"ppm"<<std::endl;
		std::cout<<"La qualité de l'air est : "<<capteurs.computeQualiteAir(module, co2, date)<<std::endl;
		capteurs.pushbackTopic("ventilation/#");
		cout << "type quit to quit" << endl;
		string in;
		do {
		cin >> in;
		}while (in != "quit");
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