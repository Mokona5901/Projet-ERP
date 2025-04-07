#include <time.h>

class QualiteAir{
public:
	void SetQualite(int module_sonoff, float qualite_air, time_t date);
	QualiteAir();
	~QualiteAir();

private:
	int module_sonoff;
	time_t date;
	float qualite_air;
};