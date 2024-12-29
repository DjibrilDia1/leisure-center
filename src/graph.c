#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Structure to represent a node in the graph
typedef struct Node {
    int activity_id;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int numActivities;
    Node** adjLists;
} Graph;

// Function to create a graph
Graph* createGraph(int activities) {
    // Créer un graphe contenant V sommets
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // ajouter une arrete entre deux sommets
}

// Function to print the graph
void displayGraph(Graph* graph) {
    // Afficher toutes les activités
}

// Function to free the graph
void freeGraph(Graph* graph) {
   // Libérer la mémoire allouée pour le graphe
}