#ifndef ACTIVITIES_H
#define ACTIVITIES_H

// declaration anticipée
struct Graph;
//struct Graph;
typedef struct Activity { // Activité == noeud du graphe
    int dest; // destination de l'activité (position dans le graphe)
    char name[100]; // nom de l'activité
    char description[100]; // description de l'activité
    struct Activity* next; // Prochain noeud de la liste
} Activity;


// Prototypes
// Créer une activité
struct Activity* newActivity(int position);
// Ajouter une activité au graphe
void add_activity(struct Graph** graph);
// Ajouter une arête entre deux activités
void add_edge(struct Graph** graph);
// Supprimer une activité du graphe
void delete_activity(struct Graph** graph);

#endif 