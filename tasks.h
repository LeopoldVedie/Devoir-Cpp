#include <string>
#include <vector>
#include <ctime>
using namespace std;

#pragma once

class Task {
public:
    string title;
    string description;
    int id;
    string status;
    string open;
    string close;
    int priority;
    vector<string> comments;
    int achiev;

    Task (string t, string d, int i, int p) ;

    Task (string t, string d, string op, int i, int p) ;

    void print (string str) ;
    /* Affiche la tâche en ajoutant str à la fin */

    void closure ();
    /* Ferme la tâche en mettant la date actuelle comme date de fermeture */

    void closure_initialization (string cl);
    /* Ferme la tâche en mettant la date cl comme date de fermeture */
};

string Date();
/* Renvoie la date et l'heure.*/

bool test_priority (Task a, Task b);
/* Test la priorité de deux tâches. */

void progress_bar (double percentage);
/* Montre la progression sous la forme d'une barre qui se remplis */