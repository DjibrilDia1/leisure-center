#ifndef ACTIVITIES_H
#define ACTIVITIES_H

// declaration anticipée
struct Graph;
//struct Graph;
typedef struct Activity { // Activité == noeud du graphe
    char name[100]; // nom de l'activité
    int id; // identifiant de l'activité
    char description[100]; // description de l'activité
    int dest; // destination de l'activité
    struct Activity* next; // Prochain noeud de la liste
} Activity;


// Prototypes
// Créer une activité
struct Activity* newActivity();
// Ajouter une activité au graphe
void add_activity(struct Graph** graph, int position);

#endif 