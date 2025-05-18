/**
 * @file AccesDonneesCapteurs.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe AccesDonneesCapteurs
 * @version 1.1
 * @date 18-05-2025
 */

#include "AccesDonneesCapteurs.h"
#include <time.h>

/**
 * @brief Construit l'objet de la classe AccesDonneesCapteurs
 */

AccesDonneesCapteurs::AccesDonneesCapteurs() {
	mqtt = new Mqtt("Rapi", "ventilation", subscription_topic_list, 
										   "0.0.0.0", // localhost pour l'instant, en attedant IP Raspberry //IP Samuel "192.168.1.102",
										   PORT, "test_user","test_pwd");
}

/**
 * @brief Détruit l'objet de la classe AccesDonneesCapteurs
 */

AccesDonneesCapteurs::~AccesDonneesCapteurs() {
	delete mqtt;
}

/**
 * @brief Méthode permettant de lire les capteurs
 * 
 * @param module_sonoff	Numéro du module Sonoff
 * @param date			Date à laquelle les données ont été récupérées
 * @param temperature	Température relevée du capteur de température
 * @param hygrometrie	Température relevée du capteur d'hygrometrie
 * @param co2			Taux de CO2 relevé du capteur de CO2
 * @return true			La lecture de tous les capteurs a réussie
 * @return false		La lecture d'au moins un capteur a échoué 
 */

//TODO Obtain ODBC database class of Enzo for database testing
bool AccesDonneesCapteurs::enregistrerQualiteAir(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2) {
	// Jeu de test pour les valeurs des capteurs
	module_sonoff = 1;
	date = time(nullptr);
	temperature = 18.4;
	hygrometrie = 65.4;
	co2 = 444.4;
	mqtt->publish("ventilation/groupe1/co2","444");
	return true;
}

/**
 * @brief Méthode permettant de déterminer la qualité de l'air
 * 
 * @param module_sonoff Numéro du module Sonoff
 * @param co2			Quantité en ppm de co2
 * @param date			Date à laquelle la qualité de l'air a été déterminée
 * @return retour		Qualité de l'air qui a été déterminée
 */

std::string AccesDonneesCapteurs::computeQualiteAir(int &module_sonoff, double &co2, time_t &date) {
	std::string retour="";
	module_sonoff = 1;
	date = time(nullptr);
	if(co2<800){
		retour = "BONNE";
	}
	if(800<=co2 && co2<1000){
		retour = "MOYENNE";
		}
		if(1000<=co2 && co2<1500){
		retour = "MAUVAISE";
	}
	if(co2>=1500){
		retour = "TRES MAUVAISE";
	}
	return retour;
}

void AccesDonneesCapteurs::pushbackTopic(std::string topic) {
	mqtt->addSubscriptionTopic(topic);
}