#include <stdio.h>
#include "menu.h"

void menu() {
    printf("\n\t\t\t==== Systeme de Gestion d'un centre de loisir ====\n");
    printf("\t\t\t1. Ajouter une nouvelle activite\n");
    printf("\t\t\t2. Afficher toutes les activites disponibles\n");
    printf("\t\t\t3. Ajouter un nouvelle utilisateur\n");
    printf("\t\t\t4. Afficher tous les utilisateurs\n");
    printf("\t\t\t5. Recommander une activite a un utilisateur\n");
    printf("\t\t\t6. Modifier une activite\n");
    printf("\t\t\t7. Supprimer une activite\n");
    printf("\t\t\t8. Modifier un utilisateur\n");
    printf("\t\t\t9. Supprimer un utilisateur\n");
    printf("\t\t\t10. Quitter\n");
    printf("\n\t\t\tEnter your choice (1-10): ");
}