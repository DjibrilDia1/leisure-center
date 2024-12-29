#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Structure pour définir un type Node:  sommet(noeud)
typedef struct Node {
    int activity_id;
    struct Node* next;
} Node;

// Structure pour définir un type graph: ensembles de sommets et d'arêtes
typedef struct Graph {
    int V; // nombre de sommets
    Node** adjLists;
} Graph;

// Fonction pour créer un graphe
struct Graph* createGraph(int activities) {
    // Créer un graphe contenant V sommets
}

// Fonction pour ajouter une arrete entre deux sommets
void addEdge(Graph* graph, int src, int dest) {
    // ajouter une arrete entre deux sommets
}

// Fonction pour afficher les activités d'un graphe
void displayGraph(Graph* graph) {
    // Afficher toutes les activités
}

// Function to free the graph
void freeGraph(Graph* graph) {
   // Libérer la mémoire allouée pour le graphe
}