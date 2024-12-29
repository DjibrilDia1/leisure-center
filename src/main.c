#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/graph.h"
#include "../include/activities.h"
#include "../include/menu.h" // inclure le fichier menu.h
#include "../include/utils.h" // inclure le fichier utils.h

#define MAX_ACTIVITIES 100 // nombre maximum d'activités

/*  Auteur:  Djibril_Dia
    Date:    29/12/2024
    Objectif: Ce projet a pour but de développer une application de gestion d'un centre de loisir en C.
*/

int main() {
    Graph* G = NULL; // initialiser le graphe
    int choix_menu1, choix_menu2;

    do {
        menu1();
        printf("\n\t\t\t\tchoix: ");

        // Lecture et validation de l'entrée utilisateur pour le premier menu
        while (scanf("%d", &choix_menu1) != 1 || (choix_menu1 != 1 && choix_menu1 != 2)) {
            while (getchar() != '\n'); // Efface l'entrée invalide du buffer
            printf("\n\t\t\t\tEntree invalide. Veuillez entrer 1 pour continuer ou 2 pour quitter.\n");
            printf("\n\t\t\t\tchoix: ");
        }

        switch (choix_menu1) {
            case 1:
                // effacee l'écran avant d'afficher le menu2
                clear_screen();
                menu2();
                // Lecture et validation de l'entrée utilisateur pour le second menu
                printf("\n\t\t\t\tchoix: ");
                while (scanf("%d", &choix_menu2) != 1 || (choix_menu2 < 0 || choix_menu2 > 12)) {
                    while (getchar() != '\n'); // Efface l'entrée invalide du buffer
                    printf("\n\t\t\t\tEntree invalide. Veuillez entrer un nombre entre 0 et 12.\n");
                    printf("\n\t\t\t\tchoix: ");
                }
                break;

            case 2:
                exit(0);
                break;

            default:
                clear_screen();
                break;
        }

        clear_screen();
    } while (choix_menu1 != 2);

    return 0;
}
