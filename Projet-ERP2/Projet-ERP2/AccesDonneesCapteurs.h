/**
 * @file AccesDonneesCapteurs.h
 * @author Samuel Tadebois-Louchart
 * @brief Déclaration de la classe AccesDonneesCapteurs
 * @version 1.1
 * @date 06-05-2025
 */

#include <time.h>
#include <thread>
#include "Mqtt.h"
#define PORT 35353

class AccesDonneesCapteurs {
public:
	bool enregistrerQualiteAir(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2);
	std::string computeQualiteAir(int &module_sonoff, double &co2, time_t &date);
	void pushbackTopic(const std::string &topic);
	AccesDonneesCapteurs();
	~AccesDonneesCapteurs();
private:
	double co2;
	double temperature;
	double hygrometrie;
	int module_sonoff;
	time_t date;
	std::vector<std::string> subscription_topic_list;
	Mqtt *mqtt = nullptr;
};