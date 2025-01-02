#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "activities.h"
#include "graph.h"
# define MAX_ACTIVITIES 100 // utilisé pour allouer de la mémoire pour le graphe

// variable globale pour compter le nombre d'activités indépendamment de MAX_ACTIVITIES
int count = 0;

// Fonction pour créer une nouvelle activité sans insertion dans un graphe
struct Activity* newActivity(int position) {

    // Allouer de la mémoire pour une nouvelle activité
    struct Activity* new_activity = (Activity*)malloc(sizeof(Activity));
    if(new_activity == NULL){
        printf("Erreur lors de l'allocation de la mémoire pour une nouvelle activite\n");
        exit(1);
    }

    new_activity->dest = position;

    // Lire les informations d'une activité,
    printf("Entrez le nom de l'activite (max 50 caracteres) : ");
    while (getchar() != '\n'); // Vider le tampon d'entrée
    fgets(new_activity->name,sizeof(new_activity->name),stdin);
    new_activity->name[strcspn(new_activity->name, "\n")] = '\0'; // supprimer le '\n' à la fin du nom

    printf("Entrez la description de l'activite (max 200 caracteres) : ");
    fgets(new_activity->description, sizeof(new_activity->description), stdin);
    new_activity->description[strcspn(new_activity->description, "\n")] = '\0';

    //Initialiser le pointeur suivant à NULL
    new_activity->next = NULL;

    return new_activity;
}


void add_activity(struct Graph** graph) {

    // Créer une nouvelle activité et l'ajouter au graphe
    int position;
    printf ("Entrez la position de l'activite (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &position);

    // Vérifier si la position est valide
    if (position < 0 || position >= (*graph)->max_V) {
        printf("Position invalide. Assurez-vous que la position est entre 0 et %d.\n", (*graph)->max_V - 1);
        return;
    }

    if ((*graph)->head[position] != NULL) {
        printf("Une activite existe déjà à cette position.\n");
        return;
    }

    // Ajouter une nouvelle activité à la position donnée
    (*graph)->head[position] = newActivity(position);
    (*graph)->V++;
    printf("Activite ajoutee au graphe a la position %d.\n", position);
    count++; // incrementer le nombre d'activités

}

void add_edge(struct Graph** graph) {
    // Ajouter une arête entre deux activités
    int src, dest;
    printf("\nActivites disponibles:\n");
    printGraph(*graph);
    
    printf("\nEntrez l'ID de l'activite source (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &src);
    
    printf("Entrez l'ID de l'activite destination (0-%d): ", (*graph)->max_V - 1);
    scanf("%d", &dest);

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

    // Ajouter une arête entre les deux activités
    struct Activity* temp = (*graph)->head[src];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = (*graph)->head[dest];
    printf("Arete ajoutee entre les activites %d et %d.\n", src, dest);
}

