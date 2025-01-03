#include <stdio.h>
#include "menu.h"

void menu1(){
    // interface de l'accueil
    printf("\n\t\t*******************************************\n");
    printf("\t\t                    ACCUEIL                     \n");
    printf("\t\t******************************************\n");
    printf("\n\t\t\tBIENVENUE DANS L'APPLICATION"); 
    printf("\n\n\t\t\t           DE");
    printf("\n\n\t\t\t GESTION D'UN CENTRE DE LOISIRS\n");
    printf("\n\t\t Tapez 1 pour continuer.\n");
    printf("\n\t\t Tapez 2 pour quitter.\n");
}

void menu2() {
    // interface du sous menu
    printf("\n\t***************************************************\n");
    printf("\t\t                MENU                         \n");
    printf("\t**************************************************\n");
    printf("\n\t\t1. Ajouter une nouvelle activite\n");
    printf("\t\t2. Afficher toutes les activites disponibles\n");
    printf("\t\t3. Gerer activites\n");
    printf("\t\t4. Supprimer activites\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\t\t5. Ajouter un utilisateur ou plusieurs utilisateurs\n");
    printf("\t\t6. Afficher utilisateurs\n");
    printf("\t\t7. Modifier un utilisateur\n");
    printf("\t\t8. Supprimer un utilisateur\n");
    printf("\t\t9. Recommander une activite a un utilisateur\n");
    printf("\t\t10. Quitter\n");
    printf("\n\tEnter your choice (1-10): ");
}

void menu_addUser(){
    // interface pour ajouter un utilisateur
    printf("\n\t\t**************** Ajouter utilisateur******************\t\t\n");
    printf("\t\t*****************Creation d'un nouveau dossier**********\t\t\n\n");
    printf("\t\t1 Pour creer un nouveau utilisateur.\n");
    printf("\t\t0 Pour retour au Menu \n");
}
