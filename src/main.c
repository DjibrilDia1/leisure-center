#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/graph.h"      // inclure le fichier graph.h
#include "../include/activities.h" // inclure le fichier activities.h
#include "../include/menu.h"       // inclure le fichier menu.h
#include "../include/utils.h"      // inclure le fichier utils.h
#include "../include/users.h"      // inclure le fichier users.h

#define MAX_ACTIVITIES 100 // nombre maximum d'activités(NODES)
#define MAX_USERS 100      // nombre maximum d'activités(NODES)

/*
    Auteur: Djibril_Dia
    Date:   29/12/2024
    Objectif: Ce projet a pour but de développer une application de gestion d'un centre de loisir en C.
*/

int main(void) {
    // Initialisation du graphe
    struct Graph *graph = NULL;
    // Réserver de la mémoire pour les utilisateurs
    struct User *users = malloc(MAX_USERS * sizeof(struct User));
    // Créer un graphe avec un nombre de sommets donné
    graph = createGraph(MAX_ACTIVITIES);
    // Variables pour les choix des menus
    int choix_menu1, choix_menu2,choix_menu3 , sous_choix;

    do {
        clear_screen();
        menu1();
        printf("\n\t\tChoix: ");
        // Choix du menu et Contrôle de saisie pour le choix du menu1
        control_saisie1(&choix_menu1);

        switch (choix_menu1) {
            case 1:
                clear_screen();
                do
                    {
                        menu2();
                        printf("\n\t\tChoix: ");
                        control_saisie1(&choix_menu2);  // Now validates for full menu range

                        switch (choix_menu2) {
                            case 1:
                                // Ajouter une activité dans le graphe
                                do {
                                    clear_screen();
                                    add_activity(&graph);
                                    // Contrôle de saisie
                                    printf("\n\t\tContinuer? (1=Oui, 0=Non): ");
                                    control_saisie(&sous_choix);
                                } while (sous_choix == 1);
                                clear_screen();
                                break;

                            case 2:
                                // Afficher le graphe
                                clear_screen();
                                if (graph != NULL) {
                                    printGraph(graph);
                                } else {
                                    printf("\n\tLe graphe est vide.\n");
                                }
                                wait_for_keypress();
                                clear_screen();
                                break;

                            case 3:
                                // Gérer les activités
                                // Connecter deux activités
                                do {
                                    clear_screen();
                                    if (graph != NULL && graph->V >= 2) {
                                        add_edge(&graph);
                                        printf("\nContinuer a connecter des activites? (1=Oui, 0=Non): ");
                                        control_saisie(&sous_choix);
                                    } else {
                                        printf("\nAjoutez au moins deux activites avant de les connecter.\n");
                                        wait_for_keypress();
                                        sous_choix = 0;
                                    }
                                } while (sous_choix == 1);
                                clear_screen();
                                break;
                            case 4:
                                // Supprimer une ou plusieurs activités dans un graph
                                do {
                                    clear_screen();
                                    if (graph != NULL && graph->V > 0) {
                                        delete_activity(&graph);
                                        printf("\nContinuer a supprimer des activites? (1=Oui, 0=Non): ");
                                        control_saisie(&sous_choix);
                                    } else {
                                        printf("\nLe graphe est vide.\n");
                                        wait_for_keypress();
                                        sous_choix = 0;
                                    }
                                } while (sous_choix == 1);
                                clear_screen();

                                break;
                            
                            case 5 :// Ajouter un ou plusieurs utilisateurs
                                do {
                                    clear_screen();
                                    menu_addUser();
                                    // Contrôle de saisie
                                    printf("\n\t\tChoix: ");
                                    // Choix du menu et Contrôle de saisie pour le choix du menu1
                                    control_saisie(&choix_menu3);

                                    switch (choix_menu3) {
                                        case 1:
                                            do {
                                                clear_screen();
                                                menu_addUser();
                                                add_users(users);
                                                // Contrôle de saisie
                                                printf("\n\t\tContinuer? (1=Oui, 0=Non): ");
                                                control_saisie(&sous_choix);
                                            } while (sous_choix == 1);
                                            clear_screen();
                                            break;

                                        case 0:
                                            // Retour au menu
                                            clear_screen();
                                            break;

                                        default:
                                            // Entrée invalide
                                            getchar();
                                            clear_screen();
                                            break;
                                    }
                                } while (sous_choix == 1);
                                clear_screen();

                            case 6:
                                // Afficher les utilisateurs
                                clear_screen();
                                display_users(users);
                                wait_for_keypress();
                                clear_screen();
                                break;
                            default:
                                break;

                            case 7:
                                // Modifier un utilisateur
                                do {
                                    clear_screen();
                                    mod_users(users);
                                    printf("\nContinuer a modifier des utilisateurs? (1=Oui, 0=Non): ");
                                    control_saisie(&sous_choix);
                                } while (sous_choix == 1);
                                clear_screen();
                                break;

                            case 8: 
                                // Supprimer un utilisateur
                                do {
                                    clear_screen();
                                    delete_user(users);
                                    printf("\nContinuer a supprimer des utilisateurs? (1=Oui, 0=Non): ");
                                    control_saisie(&sous_choix);
                                } while (sous_choix == 1);
                                clear_screen();
                                break;
                        }
                    } while (choix_menu2 != 10); // boucle pour le menu2--------------------------------------------------
            break;

            case 2:
                if (graph != NULL) {
                    freeGraph(graph);
                }
                exit(0);
                break;

            default:
                clear_screen();
                break;
        }
        clear_screen();
    } while (choix_menu1 != 2); // boucle pour le menu1--------------------------------------------------

    // Libérer la mémoire allouée pour le graphe et les utilisateurs
    freeGraph(graph);
    free(users);

    return 0;
}
