#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "activities.h"
#include "graph.h"
# include "menu.h"

# define MAX_ACTIVITIES 100 // utilisé pour allouer de la mémoire pour le graphe

// variable globale pour compter le nombre d'activités indépendamment de MAX_ACTIVITIES
int count = 0;

// Fonction pour créer une nouvelle activité sans insertion dans un graphe
struct Activity* newActivity(int position) {

    // Allouer de la mémoire pour une nouvelle activité
    struct Activity* new_activity = (struct Activity*)malloc(sizeof(struct Activity));
    if(new_activity == NULL){
        printf("Erreur lors de l'allocation de la mémoire pour une nouvelle activite\n");
        exit(1);
    }

    new_activity->dest = position;

    // Lire les informations d'une activité,
    printf("\t\tEntrez le nom de l'activite (max 50 caracteres) : ");
    while (getchar() != '\n'); // Vider le tampon d'entrée
    fgets(new_activity->name,sizeof(new_activity->name),stdin);
    new_activity->name[strcspn(new_activity->name, "\n")] = '\0'; // supprimer le '\n' à la fin du nom

    printf("\t\tEntrez la description de l'activite (max 200 caracteres) : ");
    fgets(new_activity->description, sizeof(new_activity->description), stdin);
    new_activity->description[strcspn(new_activity->description, "\n")] = '\0';

    //Initialiser le pointeur suivant à NULL
    new_activity->connections = NULL;

    return new_activity;
}

// Ajouter une activité au graphe
void add_activity(struct Graph** graph) {

    // Afficher le menu_addActivities();
    menu_addActivities();

    // Créer une nouvelle activité et l'ajouter au graphe
    int position;
    printf ("\t\tEntrez la position de l'activite (1-%d): ", (*graph)->max_V - 1);
    scanf("%d", &position);

    // Vérifier si la position est valide
    if (position < 0 || position >= (*graph)->max_V) {
        printf("Position invalide. Assurez-vous que la position est entre 0 et %d.\n", (*graph)->max_V - 1);
        return;
    }

    if ((*graph)->head[position] != NULL) {
        printf("\t\tUne activite existe deja a cette position.\n");
        return;
    }

    // Ajouter une nouvelle activité à la position donnée
    (*graph)->head[position] = newActivity(position);
    (*graph)->V++;
    printf("\t\tActivite ajoutee au graphe a la position %d.\n", position);
    count++; // incrementer le nombre d'activités
}

// Ajouter une arête entre deux activités
void add_edge(struct Graph** graph) {

    void menu_Arete();
    // Ajouter une arête entre deux activités
    // src représente la position de l'activité source et dest représente la position de l'activité de destination
    int src, dest;
    printGraph(*graph);
    // Id de l'activité source
    printf("\nEntrez l'ID de l'activite source (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &src);
    // Id de l'activité de destination
    printf("Entrez l'ID de l'activite destination (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &dest);
    // controlde de saisie
    if (src < 0 || src >= (*graph)->max_V || dest < 0 || dest >= (*graph)->max_V) {
        printf("Position invalide. Assurez-vous que la position est entre 0 et %d.\n", (*graph)->max_V - 1);
        return;
    }

    if ((*graph)->head[src] == NULL) {
        printf("Aucune activite n'existe a la position source.\n");
        return;
    }

    if ((*graph)->head[dest] == NULL) {
        printf("Aucune activite n'existe a la position de destination.\n");
        return;
    }

    // creation d'une nouvelle connexion pour une activité src
    struct ActivityNode* new_node = (struct ActivityNode*)malloc(sizeof(struct ActivityNode));
    new_node->activity = (*graph)->head[dest];
    new_node->next = (*graph)->head[src]->connections;
    (*graph)->head[src]->connections = new_node;

    printf("Arete ajoutee entre les activites %d et %d.\n", src, dest);
}

// Supprimer une activité du graphe
void delete_activity(struct Graph** graph) {
    // Supprimer une activité du graphe
    // la posiiton de l'activité à supprimer
    int position;
    printGraph(*graph);
    
    printf("\n\tEntrez l'ID de l'activite a supprimer (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &position);

    // controle de saisie dela position a suprimmer
    if (position < 0 || position >= (*graph)->max_V) {
        printf("\tPosition invalide. Assurez-vous que la position est entre 0 et %d.\n", (*graph)->max_V - 1);
        return;
    }

    if ((*graph)->head[position] == NULL) {
        printf("\tAucune activite n'existe a cette position.\n");
        return;
    }

    // Supprimer l'activité à la position donnée
    free((*graph)->head[position]);
    (*graph)->head[position] = NULL;
    (*graph)->V--;
    printf("\tActivite supprimee du graphe a la position %d.\n", position);
    count--; // décrémenter le nombre d'activités
}

// Recommander une activité
void recommend_activity(struct Graph* graph){
    if(!graph || graph->V == 0){
        printf("\tLe graphe est vide.\n");
        return;
    }    
} 
