/**
 * @file QualiteAir.h
 * @author Samuel Tadebois-Louchart
 * @brief Declaration de la classe QualiteAir
 * @version 1.0
 * @date 07-04-2025
 */

#include <time.h>
#include <string>

class QualiteAir{
public:
	std::string SetQualite(int &module_sonoff, float &qualite_air, time_t &date);
	QualiteAir();
	~QualiteAir();

private:
	int module_sonoff;
	time_t date;
	float qualite_air;
};