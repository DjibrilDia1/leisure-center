#ifndef GRAPH_H
#define GRAPH_H
#include "activities.h"

// Déclaration anticipée de Activity
struct Activity;

// Définit un nouveau type nommé Graph
 struct Graph{  // liste adjacent
    int V; // nombre de sommets
    int max_V; // max sommets
    struct Activity** head;
} ;

struct Graph* createGraph(int max_V) ; // Fonction pour créer un graphe avec un nombre de sommets donné

#endif