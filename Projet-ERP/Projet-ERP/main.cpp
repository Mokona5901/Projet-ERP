/**
 * @file main.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Declaration de la classe
 * @version 1.0
 * @date 07-04-2025
 */

#include "AccesDonneesCapteurs.h"
#include "QualiteAir.h"
#include <iostream>
#include <ctime>

int main() {
    AccesDonneesCapteurs capteurs;
    int module;
    time_t date;
    double temperature, hygrometrie, co2;
    QualiteAir qualite;
    float qualite_air;

    if (capteurs.LireCapteurs(module, date, temperature, hygrometrie, co2)) {
        std::cout<<"Lecture des capteurs réussie: "<<std::endl;
        std::cout<<"Module: "<<module <<std::endl;
        std::cout<<"Date: "<<std::asctime(std::localtime(&date))<<std::endl;
        std::cout<<"Température: "<<temperature<<"°C"<<std::endl;
        std::cout<<"Hygrométrie: "<<hygrometrie<<"%"<<std::endl;
        std::cout<<"CO2: "<<co2<<"ppm"<<std::endl;
    }
    else {
        std::cerr << "Erreur de lecture des capteurs"<<std::endl;
        std::cin.get();
    }
    
    std::cout<<"Taux de CO2 en ppm: ";
    std::cin>>qualite_air;
    std::cout<<"La qualité de l'air est : "<< qualite.SetQualite(module, qualite_air, date) << std::endl;
	std::cin.get();
	std::cin.get();
    //std::cerr<<"Erreur de récupération de la qualité de l'air"<<std::endl;
    //std::cin.get();

    return 0;
}

/*
#include "Mqtt.h"

int main() {
*/
    /**
     *  List in which all subscription topics are stored that the broker should subscribe too
     */
/*    vector<string> subscription_topic_list;
    subscription_topic_list.push_back("subscribe/test");
    subscription_topic_list.push_back("subscribe/test2");
*/
    /*
     * Create a new Client named "pc-client" that publishes on "publish/test".
     * This broker has the IP address "192.168.1.100" and the port 1883.
     * The username is set to "user" whith password "passw0rd"
     */
/*    Mqtt *mqtt = new Mqtt("pc-client", "publish/test", subscription_topic_list, "192.168.1.30", 1883, "user", "passw0rd");

    // If you don't want to use credentials, use this function
    // Mqtt *mqtt = new Mqtt("pc-client", "publish/test", subscription_topic_list, "192.168.1.30", 1883);

    mqtt->publish("publish works");
    mqtt->subscribe();

    cout << "type quit to quit" << endl;
    string in;
    do {
     cin >> in;
    }while (in != "quit");

    delete mqtt;

    return 0;
}

*/