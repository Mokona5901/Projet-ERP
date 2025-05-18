# Projet ERP - Application de Qualité de l'Air

## Description

Ce projet permet de lire des données de capteurs (température, hygrométrie, CO2) via MQTT et d'évaluer la qualité de l'air. Il utilise une application console basée sur wxWidgets, communiquant avec un broker MQTT Mosquitto configuré localement.

---

## 1. Prérequis

* Un système Linux avec `mosquitto` installé (broker MQTT)
* Bibliothèque `libmosquittopp` installée pour le client MQTT en C++
* wxWidgets installée pour la compilation de l’application
* Un compilateur C++ supportant C++17 ou supérieur
* Accès root ou sudo pour configurer Mosquitto

---

## 2. Installation et configuration

### 2.1. Configuration du broker Mosquitto

Le broker MQTT doit être configuré pour écouter sur le port 35353 en local, avec une authentification utilisateur.

* **Fichier de configuration Mosquitto**

  Si le fichier `/etc/mosquitto/conf.d/mosquitto.conf` **n'existe pas encore**, créez-le avec ce contenu :

  ```conf
  listener 35353 localhost
  allow_anonymous false
  password_file /etc/mosquitto/passwd_test_user
  ```

  Si ce fichier existe, veuillez vérifier que son contenu correspond ou adaptez-le en conséquence.

* **Fichier des utilisateurs MQTT**

  Pour créer un fichier de mots de passe, utilisez la commande suivante (remplacez `test_user` par votre utilisateur désiré) :

  ```bash
  sudo mosquitto_passwd -c /etc/mosquitto/passwd_test_user test_user
  ```

  Si le fichier existe déjà et que vous souhaitez ajouter ou modifier un utilisateur, utilisez :

  ```bash
  sudo mosquitto_passwd /etc/mosquitto/passwd_test_user test_user
  ```

  Vous serez invité à saisir et confirmer un mot de passe.

* **Service systemd**

  Créez (ou vérifiez) le fichier `/etc/systemd/system/ProjetERP-mosquitto.service` avec ce contenu :

  ```ini
  [Unit]
  Description=Mosquitto Broker pour ProjetERP
  After=network.target

  [Service]
  ExecStart=/usr/sbin/mosquitto -c /etc/mosquitto/conf.d/mosquitto.conf
  Restart=on-failure
  User=mosquitto
  Group=mosquitto

  [Install]
  WantedBy=multi-user.target
  ```

* **Activation et démarrage**

  Rechargez systemd, activez et démarrez le service :

  ```bash
  sudo systemctl daemon-reload
  sudo systemctl enable ProjetERP-mosquitto.service
  sudo systemctl start ProjetERP-mosquitto.service
  sudo systemctl status ProjetERP-mosquitto.service
  ```

---

### 2.2. Compilation de l'application

* Assurez-vous que les bibliothèques wxWidgets et mosquittopp sont installées sur votre système.

* Compilez les sources `App.cpp`, `AccesDonneesCapteurs.cpp`, `Mqtt.cpp` avec les drapeaux nécessaires.

* Exemple avec `g++` :

  ```bash
  g++ -std=c++17 -o ProjetERP App.cpp AccesDonneesCapteurs.cpp Mqtt.cpp `wx-config --cxxflags --libs` -lmosquittopp -lpthread
  ```

  Adaptez selon votre environnement.

---

## 3. Utilisation

* Lancez l’application compilée :

  ```bash
  ./ProjetERP
  ```

* L’application se connectera au broker MQTT local sur le port 35353, lira les données simulées des capteurs, affichera les valeurs et la qualité de l’air dans la console.

* Pour quitter, tapez `quit` ou `q` dans la console.

---

## 4. Notes supplémentaires

* Le projet utilise des valeurs de test simulées pour les capteurs (température, hygrométrie, CO2).

* La classe MQTT est configurée pour publier sur `ventilation/groupe1/co2` et s’abonner au topic `ventilation/groupe1/#`.

* Vous pouvez adapter les topics et l’adresse IP du broker dans le code source si nécessaire.

---