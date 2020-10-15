# Devoir-C-++
devoir de c++ to do list

Compilation


Pour compiler le programme :
g++ main.cpp fonction.cpp tasks.cpp TODO_list.cpp -o Todo_list


Fonctionnalité


Fonction Add

Permet de rajouter une tâche. Elle prend jusqu’à 3 paramètres : --title, --description et --priority.

add --title "title"  --description "description"  --priority "priority" 

Permet d’ajouter une tache de titre title pour description description pour priorité priority (un entier) et pour date de début date.

Exemple :
.\Todo_list.exe add --title "faire les courses" --description "acheter du lait et des œufs" --priority "1" 


Fonction Close 

Permet de terminer une tâche avec son id.

close --id "id "  

Exemple :
.\Todo_list.exe close –id 0

Permet de clore la première tâche de la to do list.  

Fonction Change

Permet de modifier l’avancement, le titre, la priorité ou la description d’une tâche grâce à son identifiant.

change --title "new_title" --id 0

Change le titre title en new_title dans la première tâche de la to do list

Exemple :
.\Todo_list.exe change –title "aller au supermarché" --id 0


Fonction Comments

Permet de commenter une tâche

Exemple :
.\Todo_list comments –comments "il faudrait le faire avant 16h" --id 0

Fonction Print

Permet d’imprimer la to do list

Exemple :
.\Todo_list print

Seules les tâches non accomplies sont renvoyées. Pour voir celles finies, il faut spécifier une priorité -1 au print

Exemple :
.\Todo_list print –priority -1

On peut donc renvoyer toutes les tâches ayant une priorité donnée en remplaçant le -1 par un autre entier

	Fonction del

Permet de supprimer la to do list.

Exemple :
.\Todo_list del

	Fonction --file

Permet de dire dans quelle fichier to do list il faut faire les modifications et les ajouts (sinon ils se font automatiquement dans le fichier list.todo)

Exemple :
.\Todo_list –file "list_2.todo" add --title "faire une deuxième to do list" --priority 3

Cette ligne crée un deuxième fichier donc une deuxième to do list et ajout dans celle-ci une nouvelle tâche.
