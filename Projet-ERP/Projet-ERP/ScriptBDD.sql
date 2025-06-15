-- Script pour la BDD du Projet ERP

CREATE TABLE mesure_qualite_air (
    id_mesure_qualite_air SERIAL PRIMARY KEY,
    module_id INTEGER NOT NULL, 
    temperature DOUBLE PRECISION NOT NULL,
    hygrometrie DOUBLE PRECISION NOT NULL,
    co2 DOUBLE PRECISION NOT NULL,
    qualite_air REAL NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE capteur (
    id_capteur SERIAL PRIMARY KEY,
    mesure_qualite_air_id INTEGER NOT NULL,
    sonoff_ip TEXT NOT NULL
);

CREATE TABLE zone (
    id_zone SERIAL PRIMARY KEY,
    module_id INTEGER NOT NULL,
    nom TEXT NOT NULL,
    coordonnees_x INTEGER NOT NULL,
    coordonnees_y INTEGER NOT NULL,
    adresse_ip_ventilateur TEXT NOT NULL,
    puissance_actuelle_pourcentage INTEGER NOT NULL,
    puissance_demandee_pourcentage INTEGER NOT NULL ,
    date TIMESTAMP NOT NULL
);

CREATE TABLE mesure_ventilation (
    id_mesure_ventilation SERIAL PRIMARY KEY,
    module_id INTEGER NOT NULL,
    debit_air REAL NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE utilisateur (
    id SERIAL PRIMARY KEY,
    login TEXT NOT NULL,
    mdp_hash TEXT NOT NULL,
    is_admin BOOLEAN NOT NULL
);
