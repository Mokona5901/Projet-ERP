#!/bin/bash
##### REMPLACEZ nom_user par votre login
##### REMPLACEZ nomBD par le nom que vous voulez donner à votre BD
dropdb -h serveur -U eflament ProjetERP
createdb -h serveur -U eflament ProjetERP
psql -h serveur -U eflament -d ProjetERP < ./ScriptBDD.sql