#ifndef GRAPH_H
#define GRAPH_H
#include "activities.h"

/*
	structure graphe:
	type du structure : Graph
	petite_description: cette structure permet de créer un graphe avec un nombre de sommets donné
*/
 struct Graph{  // liste adjacent
    int V; // nombre de sommets
    int max_V; // max sommets
    struct Activity** head; // Crée un tableau de pointeurs vers des activités
    // İl devra etre initialisé avec malloc(max_V * sizeof(struct Activity*));
} ;


struct Graph* createGraph(int max_V) ; // Fonction pour créer un graphe avec un nombre de sommets donné
void printGraph(struct Graph* graph); // Fonction pour afficher le graphe
void freeGraph(struct Graph* graph); // Fonction pour libérer la mémoire allouée pour le graphe

#endif