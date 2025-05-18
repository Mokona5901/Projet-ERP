/**
 * @file Mqtt.cpp
 * @author Samuel Tadebois-Louchart
 * @brief Implémentation de la classe Mqtt
 * @version 1.1
 * @date 18-05-2025
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
	cout << TAG << "Subscription succeeded." << endl;
}

void Mqtt::on_message(const struct mosquitto_message *message) {
	string payload = string(static_cast<char *>(message->payload), message->payloadlen);
	string topic = string(message->topic);
	cout << TAG << "payload: " << payload << endl;
	cout << TAG << "topic: " << topic << endl;
}

void Mqtt::on_disconnect(int rc) {
	cout << TAG << "disconnection(" << rc << ")" << endl;
}

void Mqtt::on_connect(int rc)
{
    if (rc == 0) {
        cout << TAG << "connected with server" << endl;
        /*
         * Dès que la connexion est établie, on s’abonne à tous les topics présents dans la liste.
         * Ceci permet d'assurer que la souscription est toujours active même après une reconnexion.
         */
        if (!subscription_topic_list.empty()) {
            if (subscribe()) {
                cout << TAG << "All topics subscribed successfully." << endl;
            } else {
                cerr << TAG << "Subscription failed." << endl;
            }
        }
    } else {
        cout << TAG << "impossible to connect with server(" << rc << ")" << endl;
    }
}

void Mqtt::on_publish(int mid)
{
	cout << TAG << "Message (" << mid << ") succeed to be published " << endl;
}

void Mqtt::addSubscriptionTopic(const std::string& topic) {
    subscription_topic_list.push_back(topic);
    subscribe();
}