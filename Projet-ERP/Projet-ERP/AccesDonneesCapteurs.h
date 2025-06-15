/**
 * @file AccesDonneesCapteurs.h
 * @author Samuel Tadebois-Louchart
 * @brief Déclaration de la classe AccesDonneesCapteurs
 * @version 1.1
 * @date 18-05-2025
 */

#include <time.h>
#include <thread>
#include "Mqtt.h"
#define PORT 35353

class AccesDonneesCapteurs {
public:
	bool enregistrerQualiteAir(int &module_sonoff, time_t &date, double &temperature, double &hygrometrie, double &co2);
	float computeQualiteAir(double &co2);
	void pushbackTopic(std::string topic);
	AccesDonneesCapteurs();
	~AccesDonneesCapteurs();
private:
	double co2;
	double temperature;
	double hygrometrie;
	int module_sonoff;
	std::vector<std::string> subscription_topic_list;
	time_t date;
	Mqtt *mqtt = nullptr;
};