#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/utils.h" // inclure le fichier utils.h
#include "../include/graph.h"   // inclure le fichier graph.h
#include "../include/users.h"  // inclure le fichier users.h
#include "../include/auth.h"  // inclure le fichier auth.h
#include "../include/admin_and_users.h" // inclure le fichier admin_and_users.h
#include "../include/menu.h" // inclure le fichier menu.h

#define MAX_ACTIVITIES 100 // nombre maximum d'activités(NODES)
#define MAX_USERS 100      // nombre maximum d'utilisateurs

/*
    Auteur: Djibril_Dia
    Date:   29/12/2024
    Objectif: Ce projet a pour but de développer une application de gestion d'un centre de loisir en C.
*/

int main(void) {
    // Initialisation du graphe
    struct Graph* graph = createGraph(MAX_ACTIVITIES);
    // Réserver de la mémoire pour les utilisateurs
    struct User* users = malloc(MAX_USERS * sizeof(struct User));
    char username[50], password[50];
    int role,choice,user_id;
    
    // Pour se conneceter en tant qu'administrateur ou utilisateur
    clear_screen();
    menu_connexion();
    printf("\n\tBienvenue dans le systeme de gestion\n");
    printf("\n\tNom d'utilisateur: ");
    scanf("%s", username);
    printf("\tMot de passe: ");
    scanf("%s", password);
    
    role = authenticate(username, password);
    
    if (role == ROLE_ADMIN) {
        handle_admin(&graph, users);
    }
    else if (role == ROLE_USER) {
        //handle_user_menu(graph, users, user_id);
    }
    else {
        printf("Authentification echouee.\n");
        return 1;
    }

    // Libérer la mémoire allouée pour le graphe et les utilisateurs
    freeGraph(graph);
    free(users);

    return 0;
}
