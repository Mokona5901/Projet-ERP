-- Script pour la BDD du Projet ERP
CREATE TABLE Capteurs (integer id PRIMARY KEY NOT NULL, integer id_module FOREIGN KEY NOT NULL, double precision temperature NOT NULL, double precision hygrometrie NOT NULL, double precision co2 NOT NULL, timestamp date NOT NULL)
CREATE TABLE QualiteAir (integer id PRIMARY KEY NOT NULL, integer id_module FOREIGN KEY NOT NULL, real qualite_air NOT NULL, timestamp date NOT NULL)
CREATE TABLE MesuresVentilation (id integer PRIMARY KEY NOT NULL, id_module integer FOREIGN KEY NOT NULL, debit_air double precision NOT NULL, puissance_ventilation integer NOT NULL, date timestamp NOT NULL)
CREATE TABLE ParametresVentilation (id integer PRIMARY KEY NOT NULL, id_module integer FOREIGN KEY NOT NULL, puissance_demandee integer NOT NULL, date timestamp NOT NULL)
CREATE TABLE Utilisateurs (id integer PRIMARY KEY NOT NULL, login text NOT NULL NOT NULL, mdp_hash text NOT NULL, roles text NOT NULL)