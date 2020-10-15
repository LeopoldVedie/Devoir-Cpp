#include <vector>
#include <tuple>
#include "tasks.h"
using namespace std;

#pragma once 

class To_Do {
private:
    int nb;
    vector<Task> list; 

public: 

    To_Do () ;

    void print (int p) ;
    /* Renvoie les tâches dont la priorité est supérieure à p. */

    string add_To_Do (string t, string d, int p) ;
    /* Ajoute une tâche avec la date actuelle comme date d'ouverture. */

    void add_initialization (string t, string d, int p, string op) ;
    /* Ajoute une tâche qui avait déjà été rentrée dans le fichir texte. */

    int position (string titre) ;
    /* Renvoie la position dans la liste de la première tâche nommée nom */

    int position (int ID) ;
    /* Renvoie la position dans la liste de la tâche désignée par son identifiant ID. */

    void change_priority (int ID, int p) ;
    /* Change la priorité d'une tâche désignée par son identifiant ID. */

    void add_comments (int ID, string c) ;
    /* Ajoute à un commentaire à une tâche par son identifiant ID. */

    void change_achiev (int ID, int a) ;
    /* Change l'avancement de la tâche dont l'identifiant est ID. */

    void change_title (int ID, string t);
    /* Change le titre de la tâche dont l'identifiant est ID*/

    void change_description (int ID, string descrip);
    /* Change la description de la tache dont l'identifiant est ID*/

    string close (int ID) ;
    /* Ferme une tâche et renvoie la date de fermeture pour qu"elle puisse être écrite dans le fichier texte. */

    void close_initialization (int ID, string cl) ;
    /* Ferme une tâche déjà enregistrée dans le fichier texte.*/

};