-- Script pour la BDD du Projet ERP

CREATE TABLE Capteurs (
    id SERIAL PRIMARY KEY,
    id_module INTEGER NOT NULL,
    temperature DOUBLE PRECISION NOT NULL,
    hygrometrie DOUBLE PRECISION NOT NULL,
    co2 DOUBLE PRECISION NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE QualiteAir (
    id SERIAL PRIMARY KEY,
    id_module INTEGER NOT NULL,
    qualite_air REAL NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE MesuresVentilation (
    id SERIAL PRIMARY KEY,
    id_module INTEGER NOT NULL,
    debit_air DOUBLE PRECISION NOT NULL,
    puissance_ventilation INTEGER NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE ParametresVentilation (
    id SERIAL PRIMARY KEY,
    id_module INTEGER NOT NULL,
    puissance_demandee INTEGER NOT NULL,
    date TIMESTAMP NOT NULL
);

CREATE TABLE Utilisateurs (
    id SERIAL PRIMARY KEY,
    login TEXT NOT NULL,
    mdp_hash TEXT NOT NULL,
    roles TEXT NOT NULL
);
