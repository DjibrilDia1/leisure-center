#include "utils.h"
#include <windows.h> // pour utiliser system("cls") sur Windows
#include <stdio.h>

// fonction pour effacer l'écran
void clear_screen() {
#ifdef _WIN32
    system("cls"); // clear system pour windows
#endif
}

// fonction pour controler la saisie
void control_saisie1(int *choix) {
    char buffer[100];
    int valid;
    do {
        valid = scanf("%d", choix);
        fgets(buffer, sizeof(buffer), stdin); // Clear input buffer
        
        if (valid != 1 || (*choix < 1 || *choix > 11)) { // Allow choices 1-10 for main menu
            printf("\n\t\tEntree invalide. Veuillez entrer un nombre entre 1 et 11.\n");
            printf("\n\t\t\t\tChoix: ");
        }
    } while (valid != 1 || (*choix < 1 || *choix > 11));
}

void control_saisie(int *choix) {
    char buffer[100];
    int valid;
    do {
        valid = scanf("%d", choix);
        fgets(buffer, sizeof(buffer), stdin); // Clear input buffer
        
        if (valid != 1 || (*choix != 0 && *choix != 1)) {
            printf("\n\t\t\t\t1 pour continuer");
            printf("\n\t\t\t\t0 pour retourner au menu\n");
            printf("\n\t\t\t\tChoix: ");
        }
    } while (valid != 1 || (*choix != 0 && *choix != 1));
}

void wait_for_keypress() {
    printf("\n\n\t\tAppuyez sur Entree pour continuer...");
    while(getchar() != '\n'); // Clear any remaining characters
    getchar(); // Wait for Enter key
}
