#ifndef ACTIVITIES_H
#define ACTIVITIES_H

// declaration anticipée
struct Graph;

//struct Graph;
struct Activity { // Activité == noeud du graphe
    int dest; // destination de l'activité (position dans le graphe)
    char name[100]; // nom de l'activité
    char description[100]; // description de l'activité
    struct ActivityNode* connections; // Pointe vers le début de la liste des activités connectées
};

// Definition of ActivityNode structure
struct ActivityNode {
    struct Activity* activity; // Activité
    struct ActivityNode* next; // 
};

// Prototypes
// Créer une activité
struct Activity* newActivity(int position);
// Ajouter une activité au graphe
void add_activity(struct Graph** graph);
// Ajouter une arête entre deux activités
void add_edge(struct Graph** graph);
// Supprimer une activité du graphe
void delete_activity(struct Graph** graph);
// Recommander une activité
void recommend_activity(struct Graph* graph); 


#endif 