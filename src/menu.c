#include <stdio.h>
#include "menu.h"


void menu1(){
    // interface de l'accueil
    printf("\n\t\t***************************************************\n");
    printf("\t\t                    ACCUEIL                          \n");
    printf("\t\t**************************************************\n");
    
    printf("\n\t\t\tBIENVENUE DANS L'APPLICATION"); 
    printf("\n\n\t\t\t\t     DE");
    printf("\n\n\t\t\t GESTION D'UN CENTRE DE LOISIRS\n");
    
    printf("\n\t\t\tTapez 1 pour continuer.\n");
    printf("\n\t\t\tTapez 2 pour quitter.\n");
}

void menu2() {
    printf("\n\t\t==== Systeme de Gestion d'un centre de loisir ====\n");
    printf("\t\t1. Ajouter une nouvelle activite\n");
    printf("\t\t2. Afficher toutes les activites disponibles\n");
    printf("\t\t3. Ajouter un nouvelle utilisateur\n");
    printf("\t\t4. Afficher tous les utilisateurs\n");
    printf("\t\t5. Recommander une activite a un utilisateur\n");
    printf("\t\t6. Modifier une activite\n");
    printf("\t\t7. Supprimer une activite\n");
    printf("\t\t8. Modifier un utilisateur\n");
    printf("\t\t9. Supprimer un utilisateur\n");
    printf("\t\t10. Quitter\n");
    printf("\n\tEnter your choice (1-10): ");
}