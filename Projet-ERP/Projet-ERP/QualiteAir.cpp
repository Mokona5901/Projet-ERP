/**
 * @file QualiteAir.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe QualiteAir
 * @version 1.0
 * @date 07-04-2025
 */

#include "QualiteAir.h"

/**
 * @brief Construit l'objet de la classe AccesDonneesCapteurs
 */

QualiteAir::QualiteAir() {
    // Constructeur par défaut
}

/**
 * @brief Détruit l'objet de la classe AccesDonneesCapteurs
 */

QualiteAir::~QualiteAir() {
    // Destructeur par défaut
}

/**
 * @brief Méthode permettant de récupérer la qualité de l'air
 * 
 * @param module_sonoff Numéro du module Sonoff
 * @param qualite_air   Qualité de l'air déduite
 * @param date          Date à laquelle la qualité de l'air a été récupérée
 * @return true         La lecture de tous les capteurs a réussie
 * @return false        La lecture d'au moins un capteur a échoué 
 */

std::string QualiteAir::SetQualite(int &module_sonoff, float &qualite_air, time_t &date) {
    
    // Jeu de test pour les valeurs de la qualité de l'air
    std::string retour="";
    module_sonoff = 1;
    date = time(nullptr);
    if(qualite_air<800){
        retour = "BONNE";
    }
    if(800<=qualite_air && qualite_air<1000){
        retour = "MOYENNE";
    }
    if(1000<=qualite_air && qualite_air<1500){
        retour = "MAUVAISE";
    }
    if(qualite_air>=1500){
        retour = "TRES MAUVAISE";
    }
    return retour;
}

/*

< 800 ppm : correspond à une qualité d'air excellente 
entre 800 et 1000 ppm : correspond à une qualité d'air moyenne 
entre 1000 et 1500 ppm : correspond à une qualité d'air modérée
> 1500 ppm : correspond à une qualité d'air basse
*/