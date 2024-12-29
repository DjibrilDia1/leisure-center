#ifndef GRAPH_H
#define GRAPH_H
#include "activities.h"

// Définit un nouveau type nommé Graph
typedef struct {
    int V;
    int E;
    int **Adj;
    struct Activity* activities;
} Graph;

Graph* createGraph(int V); // permet de créer un graphe contenant V sommets
void addEdge(Graph* G, int u, int v); // permet d'ajouter une arête entre deux sommets
void displayGraph(Graph* G); // permet d'afficher le graphe
void freeGraph(Graph* G);  // permet de libérer la mémoire allouée pour le graphe

#endif