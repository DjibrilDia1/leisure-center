#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "utils.h"
#include "graph.h"
#include "menu.h"

// Taille du tableau d'utilisateurs
int taille = 0;

// Fonction pour saisir les informations du téléphone
/*
    name: saisirtel
    parametres: 1
    return value: NULL
    created by: Djibril Dia
	description: Cette fonction nous sert a recupérer les informations du numero de telephone de l'utilisateur
*/
void saisirtel(struct Numero *s) {
	// Indicatif du numero de telephone
    printf("\n\t\t\t\t\tIndicatif:");
    scanf("%s", s->indicatif);
    
	//numero de telephone avec controle de saisie
    printf("\t\t\t\t\tNumero:");
    scanf("%d", &s->numero);
    while(!s->numero){
        getchar();
        printf("\n\t\t\t\t\tEntrer un numero valide:");
        scanf("%d", &s->numero);
	}
}

// Fonction pour saisir les informations de l'etudiant
/*
    name: Ajouter des utilisateurs
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a recupérer les informations de l'utilisateur 
*/
void saisir_utilisateur(struct User *et) {
	// Saisie du prenom
    printf("\n\t\tEntrer votre Prenom:");
    scanf("%s", et->Prenom);
    // Saisie du nom
    printf("\t\tEntrer votre Nom:");
    scanf("%s", et->Nom);
    // Saisie du numero de l'utilisateur
    printf("\t\tEntrer l'ID:");
	scanf("%d", &et->numero);
	// controle de saisie
	while(!et->numero){
		getchar();
		printf("\n\t\tinvalide,Reessayer:");
		scanf("%d", &et->numero);
	}
    // Saisie du numero de telephone
    printf("\n\t\tEntrer le numero de telephone:");
    saisirtel(&et->tel);    
    printf("\n\t\t-> L'utilisateur a ete cree !\n");
}

/*
    name: Ajouter des utilisateurs
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a ajouter un utilisateurs dans un tableau d'utilisateurs 
*/
void add_users(struct User les_utilisateurs[]){
    // Saisie des informations de l'utilisateur
    saisir_utilisateur(&les_utilisateurs[taille]);
    // A chaque creation d'un nouveau etudiant , la taille augmente
    taille++;
}

/*
    name: Afficher des utilisateurs
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a afficher les informations de l'utilisateur 
*/

void display_users(struct User les_utilisateurs[]) {
    if (taille <= 0) {
        printf("\n\tAucun utilisateur enregistre.\n");
        return;
    }

    printf("\n\t=== Liste des Utilisateurs et leurs Activites ===\n");
        for (int i = 0; i < taille; i++) {
        printf("\n\tUtilisateur %d:", i + 1);
        printf("\n\tNom: %s", les_utilisateurs[i].Nom);
        printf("\n\tPrenom: %s", les_utilisateurs[i].Prenom);
        printf("\n\tTelephone: %s%d", 
            les_utilisateurs[i].tel.indicatif, 
            les_utilisateurs[i].tel.numero);
        
        // Afficher les activités de l'utilisateur
        printf("\n\tActivites: ");
        struct UserActivity* current = les_utilisateurs[i].activities;
        if (!current) {
            printf("Aucune activite");
        } else {
            while (current != NULL) {
                if (current->activity) {
                    printf("\n\t\t- %s", current->activity->name);
                }
                current = current->next;
            }
        }
        printf("\n\t------------------XXXXXXXXXXX----------------------\n");
    }
}

/*
    name: Liberer la memoire allouee pour les utilisateurs
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a liberer la memoire allouee pour les utilisateurs 
*/
void free_users(struct User *les_utilisateurs){
    // Libération de la mémoire allouée pour les utilisateurs
    free(les_utilisateurs);
}

/*
    name: Modifier un utilisateur
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a modifier les informations de l'utilisateur 
*/
void mod_users(struct User les_utilisateurs[]){
    // Modification des informations de l'utilisateurS
    int numero;
    printf("\n\t\tEntrer l'ID de l'utilisateur a modifier:");
    scanf("%d",&numero);

    for (int i = 0; i < taille; i++)
    {
        if (les_utilisateurs[i].numero == numero)
        {
            printf("\n\t\tPrenom:");
            scanf("%s", les_utilisateurs[i].Prenom);
            printf("\t\tNom:");
            scanf("%s", les_utilisateurs[i].Nom);
            printf("\t\tIndicatif:");
            scanf("%s", les_utilisateurs[i].tel.indicatif);
            printf("\t\tNumero:");
            scanf("%d", &les_utilisateurs[i].tel.numero);
            printf("\t\tID:");
            scanf("%d", &les_utilisateurs[i].numero);
            printf("\n\t\t-> Utilisateur modifie !\n");
            return;
        }
        
    }
    
}

// supprimer un utilisateur
void delete_user(struct User les_utilisateurs[]){
    // Suppression d'un utilisateur
    int numero;
    printf("\n\t\tEntrer l'ID de l'utilisateur a supprimer:");
    scanf("%d",&numero);

    for (int i = 0; i < taille; i++)
    {
        if (les_utilisateurs[i].numero == numero)
        {
            for (int j = i; j < taille; j++)
            {
                les_utilisateurs[j] = les_utilisateurs[j+1];
            }
            taille--;
            printf("\n\t\t-> Utilisateur supprime !\n");
            return;
        }
        
    }
    
}

// Ajouter une activité à un utilisateur
void add_user_activities(struct User les_utilisateurs[], struct Graph **graph) {
    // Afficher les utilisateurs
    display_users(les_utilisateurs);

    // Entrer l'ID de l'utilisateur
    int user_id;
    printf("\n\t\tEntrez l'ID de l'utilisateur: ");
    scanf("%d", &user_id);

    // Rechercher l'utilisateur
    int user_found = 0;
    for (int i = 0; i < taille; i++) {
        if (les_utilisateurs[i].numero == user_id) {

            user_found = 1;
            // vérifier si une activité est disponible
            if((*graph)->max_V == 0){
                printf("\t\tAucune activite n'est disponible.\n");
                return;
            }

            // Afficher les activités disponibles
            printf("\n\tActivites disponibles:\n");
            printGraph(*graph);

            // Entrer l'ID de l'activité
            int activity_id;
            printf("\n\tEntrez l'ID de l'activite: ");
            scanf("%d", &activity_id);

            // Vérifier si l'activité existe dans le graphe
            if (activity_id < 0 || activity_id >= (*graph)->max_V || (*graph)->head[activity_id] == NULL) {
                printf("\tActivite introuvable.\n");
                return;
            }

            // Ajouter l'activité à la liste des activités de l'utilisateur
            struct UserActivity *new_activity = (struct UserActivity *)malloc(sizeof(struct UserActivity));
            if (new_activity == NULL) {
                printf("Erreur d'allocation de memoire.\n");
                return;
            }

            // Important: Set both activity_id and activity pointer
            new_activity->activity_id = activity_id;
            new_activity->activity = (*graph)->head[activity_id]; // Set the activity pointer
            new_activity->next = les_utilisateurs[i].activities;
            les_utilisateurs[i].activities = new_activity;

            printf("\t\tActivite %s ajoutee a l'utilisateur %s %s.\n", 
                (*graph)->head[activity_id]->name,
                les_utilisateurs[i].Prenom,
                les_utilisateurs[i].Nom);

            // Afficher un message de confirmation
            printf("\t\tActivite %d ajoutee a l'utilisateur %d.\n", activity_id, user_id);

            return;
        }
    }

    // Si l'utilisateur n'est pas trouvé
    if (!user_found) {
        printf("Utilisateur introuvable.\n");
    }
}
