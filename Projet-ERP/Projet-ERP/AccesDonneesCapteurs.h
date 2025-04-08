/**
 * @file AccesDonneesCapteurs.h
 * @author Samuel Tadebois-Louchart
 * @brief Déclaration de la classe AccesDonneesCapteurs
 * @version 1.0
 * @date 07-04-2025
 */

#include <time.h>

class AccesDonneesCapteurs {
public:
    bool LireCapteurs(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2);
    AccesDonneesCapteurs();
    ~AccesDonneesCapteurs();
};
