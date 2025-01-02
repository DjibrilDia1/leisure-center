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

// Afficher le graphe
void printGraph(struct Graph* graph) {
    if (!graph) return;
    printf("\n=== Liste des activites et leurs connexions ===\n");
    for (int i = 0; i < graph->max_V; i++) {
        Activity* temp = graph->head[i];
        if (temp) {
            printf("\nActivite %d: %s\n", i, temp->name);
            printf("Description: %s\n", temp->description);
            printf("Connectee a: ");
            temp = temp->next;
            while (temp) {
                printf("%s -> ", temp->name);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

// Libérer la mémoire allouée pour le graphe
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


