/**
 * @file main.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Fichier de test pour les classes de l'étudiant 2
 * @version 1.1
 * @date 06-05-2025
 */

#include "AccesDonneesCapteurs.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include "Mqtt.h"

int main() {
    AccesDonneesCapteurs capteurs;
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

	return 0;
}