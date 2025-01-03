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
    graph->head = (struct Activity**)malloc(max_V * sizeof(struct Activity*));

    // Vérifier si l'allocation a reussi
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
    if (!graph) {
        printf("Graphe vide!\n");
        return;
    }
    
    printf("\n\t\t=== Liste des activites et leurs connexions ===\n");
    for (int i = 0; i < graph->max_V; i++) {
        // current me permet d'accéder aux éléments de la liste d'adjacence
        struct Activity* current = graph->head[i];
        if (current) {
            printf("\n\tActivite %d: %s\n", i, current->name);
            printf("\tDescription: %s\n", current->description);
            printf("\tConnectee a: ");
            // connection reçoit l'adresse de la première activité connectée
            struct ActivityNode* connection = current->connections;
            // Parcourir la liste des activités connectées a la premiére activité de la liste adjacente
            while (connection != NULL) {
                if (connection->activity) {
                    printf("\t%s -> ", connection->activity->name);
                }
                connection = connection->next;
            }
            printf("NULL\n");
        }
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->max_V; i++) {
        struct Activity* activity = graph->head[i];
        while (activity != NULL) {
            struct ActivityNode* connection = activity->connections;
            while (connection != NULL) {
                struct ActivityNode* nextConnection = connection->next;
                free(connection);
                connection = nextConnection;
            }
            struct Activity* nextActivity = NULL    ;
            free(activity);
            activity = nextActivity;
        }
    }
    free(graph->head);
    free(graph);
}
