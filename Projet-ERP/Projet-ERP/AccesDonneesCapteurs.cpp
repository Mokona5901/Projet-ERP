/**
 * @file AccesDonneesCapteurs.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe AccesDonneesCapteurs
 * @version 1.1
 * @date 15-06-2025
 */

#include "AccesDonneesCapteurs.h"
#include <time.h>

/**
 * @brief Construit l'objet de la classe AccesDonneesCapteurs
 */

AccesDonneesCapteurs::AccesDonneesCapteurs() {
	mqtt = new Mqtt("Raspberry-Pi", "ventilation", subscription_topic_list, 
										   "0.0.0.0", // localhost, car BDD sur Raspberry
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

bool AccesDonneesCapteurs::enregistrerQualiteAir(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2) {
	// Jeu de test pour les valeurs des capteurs
	module_sonoff = 1;
	date = time(nullptr);
	temperature = 19.2;
	hygrometrie = 25.7;
	co2 = 612.4;
	return true;
}

/**
 * @brief Méthode permettant de déterminer la qualité de l'air à partir du co2
 * 
 * @param co2			Quantité en ppm de co2
 * @return retour		Qualité de l'air qui a été déterminée
 */

float AccesDonneesCapteurs::computeQualiteAir(double &co2) {

    if (co2 < 800)
        return 0.0f;
    else if (co2 < 1000)
        return 1.0f + (co2 - 800.0f) / 200.0f;
    else if (co2 < 1500)
        return 2.0f + (co2 - 1000.0f) / 500.0f;
    else if (co2 < 2000)
        return 3.0f + (co2 - 1500.0f) / 500.0f;
    else
        return 4.0f;
}

/**
 * @brief Méthode permettant d'ajouter un topic auquel on doit s'abonner
 * 
 * @param topic			Nom du topic
 */

void AccesDonneesCapteurs::pushbackTopic(std::string topic) {
	mqtt->addSubscriptionTopic(topic);
}