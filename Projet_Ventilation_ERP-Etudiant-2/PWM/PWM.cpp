#include <iostream>
#include <pigpio.h>
using namespace std;

int main()
{
	if (gpioInitialise() < 0) {
		cerr << "Erreur d'initialisation de pigpio.\n";
		return 1;
	}

	const int gpio = 18;
	gpioSetMode(gpio, PI_OUTPUT);

	int pourcentage;
	cout << "Entrez un rapport cyclique (0 à 100 %) : ";
	if (!(cin >> pourcentage)) {
		cerr << "Entrée invalide. Veuillez entrer un entier.\n";
		gpioTerminate();
		return 1;
	}

	if (pourcentage < 0 || pourcentage > 100) {
		cerr << "Valeur invalide. Doit être entre 0 et 100.\n";
		gpioTerminate();
		return 1;
	}

	int freq = 1000;
	int rapport = (pourcentage * 255) / 100;

	gpioSetPWMfrequency(gpio, freq);
	gpioPWM(gpio, rapport);

	cout << "PWM actif à " << pourcentage << " % de puissance.\n";
	cout << "Appuyez sur Entrée pour quitter...\n";

	cin.ignore();
	cin.get();

	gpioPWM(gpio, 0);
	gpioTerminate();

	return 0;
}
