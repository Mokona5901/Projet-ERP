# Documentation Code Module Ventilation

Ce répertoire contient les codes source en C++ pour les modules de contrôle et d'acquisition de données du projet de Supervision de Ventilation E.R.P. (Établissements Recevant du Public).

Les programmes sont principalement destinés à être exécutés sur un Raspberry Pi pour le pilotage (PWM) et la gestion des données (ODBC/Base de données).

---

## 🛠️ Prérequis et Dépendances

Les programmes nécessitent l'installation des librairies suivantes :

### 1. **Pilotage Matériel (Raspberry Pi)**
| Librairie | Utilisation |
| :--- | :--- |
| **`pigpio`** | **Indispensable** pour l'initialisation des GPIO et le contrôle de la Modulation de Largeur d'Impulsion (PWM) [utilisée dans `PWM.cpp` et `PWM_BDD.cpp`]. |

### 2. **Base de Données (PostgreSQL/MySQL via ODBC)**
| Librairie | Utilisation |
| :--- | :--- |
| **`Poco::Data`** | Gestion des sessions, des connexions (ODBC) et exécution des requêtes SQL [utilisée dans les fichiers `BDD.cpp`]. |
| **`Poco/Data/ODBC/Connector.h`** | Connexion spécifique via un DSN ODBC (DataSource Name). |

---

## Détails des Fichiers

| Fichier | Description | Librairies Clés | Rôle dans le Projet |
| :--- | :--- | :--- | :--- |
| **`PWM.cpp`** | **Contrôle PWM Simple.** Ce code lit un pourcentage de puissance (0-100%) en console et configure le GPIO 18 (par défaut) pour émettre un signal PWM. Programme de test. | `iostream`, `pigpio` | **Validation du Hardware :** Vérifie que le signal PWM est correctement envoyé au convertisseur 0-10V. |
| **`Connexion_BDD.cpp`** | **Lecture BDD.** Établit une connexion à la BDD via ODBC (`DSN=Projet_Ventilation_ERP`) et exécute une simple requête `SELECT` pour récupérer la dernière valeur de `puissance_demandee_pourcentage` dans la table `zone`. | `Poco::Data::ODBC`, `iostream` | **Test BDD :** Validation de la connexion et de la lecture de la consigne de pilotage. |
| **`Debit_BDD.cpp`** | **Acquisition du Débit.** Simule l'acquisition d'un débit d'air (`simulateDebitAir`) et insère cette valeur, ainsi que l'horodatage (`timestamp`), dans la table `mesure_ventilation` de la BDD toutes les 10 secondes. | `Poco::Data`, `ctime`, `random` | **Module d'Acquisition :** Représente le code du module de mesure 4-20mA (via Venturi). |
| **`PWM_BDD.cpp`** | **Pilotage Complet et BDD.** Programme principal qui gère un **asservissement simple**. Il lit une consigne de puissance en temps réel depuis l'entrée utilisateur, l'enregistre dans la BDD, et applique la puissance correspondante au GPIO via PWM, tout en mettant à jour la BDD. | `Poco::Data`, `pigpio`, `thread` | **Module de Pilotage :** Cœur du module d'actionnement de la ventilation (Gestion des commandes et de l'état). |

---



