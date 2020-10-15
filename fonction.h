#include <iostream>
#include <cstdio>
#include <fstream>
#include <tuple>
#include <string>
#include <cstring>
#include "tasks.h"
#include "TODO_list.h"
using namespace std;
#pragma once


vector<string> char_to_string_vec (int argc, char**  argv);
/* Convertit un char** en un vector<string> */

vector<string> extract (string file);
/* Lit un fichier et renvoie son contenu sous la forme d'un vector<string> */

void write (string file, const vector<string> & v_str, int i, int nb);
/* Ecrit dans le fichier file nb éléments d'un vector<string> à partir de l'indice i */

void write_string(string file, const string & str);
/* Ecrit dans le fichier file un string */


To_Do initialization(const vector<string> & v_str);
/* Permet d'interpréter les actions enregistrées dans le fichier texte. */

void add_initialization (const vector<string> & v_str, To_Do & list, int & i) ;
/* Lit le fichier sauvegardé pour ajouter des tâches à la To Do list */

void close_initialization (const vector<string> & v_str, To_Do & list, int & i);
/* Lit le fichier sauvegardé pour fermer des tâches de la To Do list */


string add (const vector<string> & v_str, To_Do & list, int & i) ;
/* Permet de rajouter une tâche à la liste */

string close(const vector<string> & v_str, To_Do & list, int & i);
/* Permet de finir une tâche de la To Do list */ 

void change (const vector<string> & v_str, To_Do & list, int & i);
/* interprete change dans le ligne de commande et dans le fichier enregistré */

void comments (const vector<string> & v_str, To_Do & list, int & i);
/* interprete comments dans le ligne de commande et dans le fichier enregistré */

void del (string file);
/* Permet de supprimez le fichier texte où est enregistré la To Do list. */