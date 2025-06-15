/**
 * @file Mqtt.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe Mqtt
 * @version 1.1
 * @date 15-06-2025
 */

#include "Mqtt.h"

Mqtt::Mqtt(string id, string publish_topic, vector<string> subscription_topic_list, string host, int port, string username, string password){
	mosqpp::lib_init();
	this->id = id;
	this->keepalive = 180;
	this->port = port;
	this->host = host;
	this->publish_topic = publish_topic;
	this->subscription_topic_list = subscription_topic_list;
	mosquittopp::username_pw_set(username.c_str(), password.c_str());

	/*
	 * Connect to an MQTT broker. This is a non-blocking call. If you use mosquitto_connect_async your client must use
	 * the threaded interface mosquitto_loop_start.
	 */
	connect_async(this->host.c_str(), this->port, this->keepalive);
	loop_start();
}

Mqtt::~Mqtt() {
	disconnect();
	loop_stop();
	mosqpp::lib_cleanup();
}

bool Mqtt::publish(string topic, string message){
	/*
	 * NULL: pointer to an int.  If not NULL, the function will set this to the message id of this particular message.
	 * This can be then used with the publish callback to determine when the message has been sent.
	 * Note that although the MQTT protocol doesn’t use message ids for messages with QoS=0, libmosquitto assigns them
	 * message ids so they can be tracked with this parameter.
	 *
	 * topic.c_str(): null terminated string of the topic to publish to.
	 *
	 * message.length(): the size of the payload (bytes). Valid values are between 0 and 268,435,455.
	 *
	 * message.c_str(): pointer to the data to send.  If message.length() > 0 this must be a valid memory location.
	 *
	 * 2: integer value 0, 1 or 2 indicating the Quality of Service to be used for the message.
	 *
	 * true: set to true to make the message retained.
	 */
	int answer = mosquittopp::publish(nullptr, topic.c_str(), message.length(), message.c_str(), 2, true);
	return (answer == MOSQ_ERR_SUCCESS);
}

bool Mqtt::subscribe() {
	bool success = true;
	for (long unsigned int i = 0; i < subscription_topic_list.size(); i++) {
		/*
		 * mosquittopp::subscribe parameters:
		 * NULL: pointer to int to store message id (optional)
		 * subscription_topic_list[i].c_str(): topic to subscribe to
		 */
		int answer = mosquittopp::subscribe(nullptr, subscription_topic_list[i].c_str());
		if (answer != MOSQ_ERR_SUCCESS) {
			success = false;
		}
	}
	return success;
}

void Mqtt::on_subscribe(int, int, const int *) {
	cout << TAG << "Abonnement réussi" << endl;
}

struct DonneesCapteurs {
    std::string heure;
    double temperature = 0.0;
    double hygrometrie = 0.0;
    double co2 = 0.0;
    std::string uniteTemperature;
};

bool parsePayloadCapteurs(const std::string& payload, DonneesCapteurs& data) {
    try {
        auto j = json::parse(payload);
        data.heure = j.value("Time", "");
        data.uniteTemperature = j.value("TempUnit", "C");

        if (j.contains("THS01")) {
            auto ths = j["THS01"];
            data.temperature = ths.value("Temperature", 0.0);
            data.hygrometrie = ths.value("Humidity", 0.0);
        } else {
            std::cerr << "Données du capteur THS01 manquantes\n";
        }

        if (j.contains("MHZ19")) {
            auto mhz = j["MHZ19"];
            data.co2 = mhz.value("CO2", 0.0);
        } else {
            std::cerr << "Données du capteur MH-Z19 manquantes\n";
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Erreur du parseur JSON: " << e.what() << "\n";
        return false;
    }
}

void Mqtt::on_message(const struct mosquitto_message *message) {
    std::string payload(static_cast<char *>(message->payload), message->payloadlen);
    std::string topic = message->topic;

    DonneesCapteurs donneesCapteurs;
    if (parsePayloadCapteurs(payload, donneesCapteurs)) {
        std::regex group_regex(R"(ventilation/groupe(\d+)/)");
        std::smatch match;
        std::string groupInfo = "N/A";

        if (std::regex_search(topic, match, group_regex) && match.size() > 1) {
            groupInfo = match[1];
        } else {
            std::cerr << TAG << "Impossible d'extraire le numéro de groupe depuis le topic" << std::endl;
        }

        std::cout << TAG << "Données du groupe " << groupInfo << " :" << std::endl
                  << "Heure: " << donneesCapteurs.heure << std::endl
                  << "Température: " << donneesCapteurs.temperature << "°" << donneesCapteurs.uniteTemperature << std::endl
                  << "Hygrométrie: " << donneesCapteurs.hygrometrie << "%" << std::endl
                  << "CO2: " << donneesCapteurs.co2 << "ppm" << std::endl
                  << "Topic: " << topic << std::endl;
    } else {
        std::cerr << TAG << "Échec de l'analyse des données capteurs" << std::endl;
    }
}


void Mqtt::on_disconnect(int rc) {
	cout << TAG << "Déconnexion(" << rc << ")" << endl;
}

void Mqtt::on_connect(int rc)
{
    if (rc == 0) {
        cout << TAG << "connecté avec le broker" << endl;
        /*
         * Dès que la connexion est établie, on s’abonne à tous les topics présents dans la liste.
         * Ceci permet d'assurer que l'abonnement est toujours actif même après une reconnexion.
         */
        if (!subscription_topic_list.empty()) {
            if (subscribe()) {
                cout << TAG << "L'abonnement aux topics voulus a été réussi" << endl;
            } else {
                cerr << TAG << "L'abonnement a échoué" << endl;
            }
        }
    } else {
        cout << TAG << "Impossible de se connecter au broker(" << rc << ")" << endl;
    }
}

void Mqtt::on_publish(int mid)
{
	cout << TAG << "Le message (" << mid << ") a bien été publié" << endl;
}

/**
 * @brief Méthode qui permet d'ajouter un topic à s'abonner, ce que subscribe() fera
 * 
 * @param topic			Nom du topic auquel il faut s'abonner
 */

void Mqtt::addSubscriptionTopic(const std::string& topic) {
    subscription_topic_list.push_back(topic);
    subscribe();
}