#include <iostream>
#include <pigpio.h>

int main()
{
	if (gpioInitialise() < 0) {
		std::cerr << "Erreur d'initialisation de pigpio.\n";
		return 1;
	}

	const int gpio = 18; // GPIO18 = pin physique 12
	gpioSetMode(gpio, PI_OUTPUT);

	int pourcentage;
	std::cout << "Entrez un rapport cyclique (1 à 100 %) : "; //Normalement depuis la BDD
	std::cin >> pourcentage;

	if (pourcentage < 1 || pourcentage > 100) {
		std::cerr << "Valeur invalide. Doit être entre 1 et 100.\n";
		gpioTerminate();
		return 1;
	}

	int freq = 1000; // 1 kHz
	int dutycycle = (pourcentage * 255) / 100; // pigpio utilise 0-255

	gpioSetPWMfrequency(gpio, freq);
	gpioPWM(gpio, dutycycle);

	std::cout << "PWM actif sur GPIO18 à " << freq << " Hz, " << pourcentage << " % de puissance.\n";
	std::cout << "Appuyez sur Entrée pour quitter...\n";
	std::cin.ignore();
	std::cin.get();

	gpioTerminate();
	return 0;
}
