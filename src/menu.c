#include <stdio.h>
#include "menu.h"

void menu_connexion(){
    // interface de connexion
    printf("\n\t\t****************************************************\n");
    printf("\t\t                    CONNEXION                     \n");
    printf("\t\t****************************************************\n");
}
void menu1(){
    // interface de l'accueil
    printf("\n\t\t****************************************************\n");
    printf("\t\t                    ACCUEIL                     \n");
    printf("\t\t****************************************************\n");
    printf("\n\t\t\tBIENVENUE DANS L'APPLICATION"); 
    printf("\n\n\t\t\t           DE");
    printf("\n\n\t\t\t GESTION D'UN CENTRE DE LOISIRS\n");
    printf("\n\t\t Tapez 1 pour continuer.\n");
    printf("\n\t\t Tapez 2 pour quitter.\n");
}

void menu2() { // menu admin
    // interface du sous menu
    printf("\n\t*******************************************************\n");
    printf("\t\t\t         MENU                         \n");
    printf("\t*******************************************************\n");
    printf("\t---------------GESTION DES ACTIVITES----------------------\n");
    printf("\t\t1. Ajouter une nouvelle activite\n");
    printf("\t\t2. Afficher toutes les activites disponibles\n");
    printf("\t\t3. Gerer activites\n");
    printf("\t\t4. Supprimer activites\n");
    printf("\n\t---------------GESTION DES UTILISATEURS--------------------\n");
    printf("\t\t5. Ajouter un utilisateur ou plusieurs utilisateurs\n");
    printf("\t\t6. Afficher utilisateurs\n");
    printf("\t\t7. Modifier un utilisateur\n");
    printf("\t\t8. Supprimer un utilisateur\n");
    printf("\t\t9. choisir des activites pour un utilisateur\n");
    printf("\n\t-----------------------------------------------------------\n");
    printf("\t\t10. Recommander une activite a un utilisateur\n");
    printf("\t\t11. Quitter\n");
    printf("\n\tEnter your choice (1-10): ");
}

// Menu de l'utilisateur
void userMenu(void) {
    printf("\n\t=== Menu Utilisateur ===\n");
    printf("\t1. Voir les activites\n");
    printf("\t2. S'inscrire a une activite\n");
    printf("\t3. Voir mes activites\n");
    printf("\t4. Deconnexion\n");
}

void menu_addUser(){
    // interface pour ajouter un utilisateur
    printf("\n\t\t***********Ajouter utilisateur******************\t\t\n");
    printf("\t\t*****************Creation d'un nouveau dossier**********\t\t\n\n");
    printf("\t\t1 Pour creer un nouveau utilisateur.\n");
    printf("\t\t0 Pour retour au Menu \n");
}

void menu_displayUserinformation(){
    // interface pour afficher les informations de l'utilisateur
    printf("\n\t\t**************** Afficher les informations de l'utilisateur*********\t\n");
    printf("\t\t*****************Informations de l'utilisateur**********\t\t\n\n");
}

void menu_addActivities(){
    // interface pour ajouter une activite
    printf("\n\t\t    *********** Activites *************\t\t\n");
    printf("\t\t******  Creation d'une nouvelle activite  **********\t\t\n\n");
}

void menu_Arete(){
    // Ajouter une connexion entre deux activités
    printf("\n\t\t*********** Activtes ******************\t\t\n");
    printf("\t\t*********** Ajouter une arrete **********\t\t\n\n");
}