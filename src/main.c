#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/graph.h"  // inclure le fichier graph.h
#include "../include/activities.h" // inclure le fichier activities.h
#include "../include/menu.h" // inclure le fichier menu.h
#include "../include/utils.h" // inclure le fichier utils.h

# define MAX_ACTIVITIES 100 // nombre maximum d'activités(NODES)

/* 
    Auteur:  Djibril_Dia
    Date:    29/12/2024
    Objectif: Ce projet a pour but de développer une application de gestion d'un centre de loisir en C.
*/

int main() {
    struct Graph *graph = NULL;
    graph = createGraph(MAX_ACTIVITIES);
    int choix_menu1, choix_menu2;
    char name[100], description[100];
    int src, dest;

    do {
        clear_screen();
        menu1();
        printf("\n\t\t\t\tChoix: ");

        while (scanf("%d", &choix_menu1) != 1 || (choix_menu1 != 1 && choix_menu1 != 2)) {
            while (getchar() != '\n');
            printf("\n\t\t\t\tEntree invalide. Veuillez entrer 1 ou 2.\n");
            printf("\n\t\t\t\tChoix: ");
        }

        switch (choix_menu1) {

            case 1: {
                clear_screen();
                menu2();
                printf("\n\t\t\t\tChoix: ");
                while (scanf("%d", &choix_menu2) != 1 || (choix_menu2 < 0 || choix_menu2 > 12)) {
                    while (getchar() != '\n');
                    printf("\n\t\t\t\tEntree invalide. Veuillez entrer un nombre entre 0 et 12.\n");
                    printf("\n\t\t\t\tChoix: ");
                }

                switch (choix_menu2) { 
                    case 1: { // Ajouter une activité dans le graph 
                        clear_screen();
                        int position;
                        printf ("Entrez la position de l'activite (0-%d): ", graph->max_V - 1);
                        scanf("%d", &position);
                        add_activity(&graph,position);
                        
                    }
                    case 2: { // Ajouter une connexion entre deux activités

                        break;
                    }

                    case 3: { // Afficher le graphe
                        
                        break;
                    }
                    default:
                        break;
                }
                wait_for_keypress();
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

    return 0;
}
