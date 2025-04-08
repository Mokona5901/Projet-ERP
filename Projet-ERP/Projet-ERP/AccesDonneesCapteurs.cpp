/**
 * @file AccesDonneesCapteurs.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Declaration de la classe AccesDonneesCapteurs
 * @version 1.0
 * @date 07-04-2025
 */

#include "AccesDonneesCapteurs.h"
#include <time.h>

/**
 * @brief Construit l'objet de la classe AccesDonneesCapteurs
 */

AccesDonneesCapteurs::AccesDonneesCapteurs() {
    // Constructeur
}

/**
 * @brief Détruit l'objet de la classe AccesDonneesCapteurs
 */

AccesDonneesCapteurs::~AccesDonneesCapteurs() {
    // Destructeur
}

/**
 * @brief Méthode permettant de lire les capteurs
 * 
 * @param module_sonoff Numéro du module Sonoff
 * @param date          Date à laquelle les données ont été récupérées
 * @param temperature   Température relevée du capteur de température
 * @param hygrometrie   Température relevée du capteur d'hygrometrie
 * @param co2           Taux de CO2 relevé du capteur de CO2
 * @return true         La lecture de tous les capteurs a réussie
 * @return false        La lecture d'au moins un capteur a échoué 
 */

bool AccesDonneesCapteurs::LireCapteurs(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2) {
    
    // Jeu de test pour les valeurs des capteurs
    module_sonoff = 1;
    date = time(nullptr);
    temperature = 22.5;
    hygrometrie = 45.0;
    co2 = 400.0;
    
    return true;
}
