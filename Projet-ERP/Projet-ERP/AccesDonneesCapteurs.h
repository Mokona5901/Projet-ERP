#include <time.h>

struct variables{
	int module_sonoff;
	time_t date;
	double temperature;
	double hygrometrie;
	double co2;
};

class AccesDonneesCapteurs{
public:
	variables LireCapteurs(struct &variables);
	AccesDonneesCapteurs();
	~AccesDonneesCapteurs();
};