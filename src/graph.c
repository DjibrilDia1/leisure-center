#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "activities.h"

int count;// meme variable globale que dans activities.c

// Créer un graph avec un nombre de sommets donné
struct Graph* createGraph(int max_V) {
    // Allouer de la mémoire pour le graphe
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Erreur : Allocation memoire échouee.\n");
        exit(1);
    }

    graph->V = 0; // Initialement, pas de nœuds
    graph->max_V = max_V;

    // Allouer de la mémoire pour la liste d'adjacence
    graph->head = (Activity**)malloc(max_V * sizeof(Activity*));
    if (graph->head == NULL) {
        printf("Erreur : Allocation mémoire échouee.\n");
        free(graph);
        exit(1);
    }
    
    // Initialiser toutes les positions à NULL
    for (int i = 0; i < max_V; i++) {
        graph->head[i] = NULL;
    }

    return graph;
}

void printGraph(struct Graph* graph){
    for(int i = 1; i <= count; i++){
        struct Activity* temp = graph->head[i];
        printf("Activite %d: ", i);
        while (temp != NULL) {
            printf("%s -> ", temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->max_V; i++) {
        struct Activity* temp = graph->head[i];
        while (temp != NULL) {
            struct Activity* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->head);
    free(graph);
}


