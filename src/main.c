#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/graph.h"  // inclure le fichier graph.h
#include "../include/activities.h" // inclure le fichier activities.h
#include "../include/menu.h" // inclure le fichier menu.h
#include "../include/utils.h" // inclure le fichier utils.h

# define MAX_ACTIVITIES 100 // nombre maximum d'activités(NODES)

/* 
    Auteur: Djibril_Dia
    Date:   29/12/2024
    Objectif: Ce projet a pour but de développer une application de gestion d'un centre de loisir en C.
*/

int main() {
    // Initialisation du graphe
    struct Graph *graph = NULL;
    // Créer un graphe avec un nombre de sommets donné
    graph = createGraph(MAX_ACTIVITIES);
    // Variables pour les choix des menus 
    int choix_menu1, choix_menu2, sous_choix;

    do {
        clear_screen();
        menu1();
        printf("\n\t\t\t\tChoix: ");

        // conrtôle de saisie pour le choix du menu1
        while (scanf("%d", &choix_menu1) != 1 || (choix_menu1 != 1 && choix_menu1 != 2)) {
            while (getchar() != '\n');
            printf("\n\t\t\t\tEntree invalide. Veuillez entrer 1 ou 2.\n");
            printf("\n\t\t\t\tChoix: ");
        }

        switch (choix_menu1) {
            case 1: {
                // effacer l'écran avant d'afficher le menu2
                clear_screen();
                menu2();
                printf("\n\t\t\t\tChoix: ");
                // controle de saisie pour le choix du menu2
                while (scanf("%d", &choix_menu2) != 1 || (choix_menu2 < 0 || choix_menu2 > 12)) {
                    while (getchar() != '\n');
                    printf("\n\tEntree invalide. Veuillez entrer un nombre entre 0 et 12.\n");
                    printf("\n\tChoix: ");
                }

                switch (choix_menu2) { 
                    case 1: { // Ajouter une activité dans le graph 
                        do
                        {
                            clear_screen();
                            add_activity(&graph);
                            printf("\n\t1 pour continuer a creer");
                            printf("\n\t0 pour annuler\n");
                            printf("\n\tchoix:");
                            while(scanf("%d",&sous_choix) != 1 ||(sous_choix != 1 && sous_choix != 0)){
                                getchar();
                                printf("\n\t1 pour continuer a creer");
                                printf("\n\t0 pour annuler\n");
                                printf("\n\tchoix:");
                            }
                        } while (sous_choix == 1);

                        break;
                    }
                    case 2: { // Afficher le graphe
                        clear_screen();
                        if (graph != NULL) printGraph(graph);
                        else printf("\n\tLe graphe est vide.\n");

                        wait_for_keypress();
                        break;
                    }

                    case 3: { 
                        
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                if (graph != NULL) {
                    //freeGraph(graph);
                }
                exit(0);
            }
            default:
                clear_screen();
                break;
        }
        clear_screen();
    } while (choix_menu1 != 2);
    
    freeGraph(graph);
    return 0;
}
