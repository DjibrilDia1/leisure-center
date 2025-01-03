#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "utils.h"

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
void display_users(struct User les_utilisateurs[]){
    // Affichage des informations de l'utilisateur
    int i;
    for(i=0;i<taille;i++){
        printf("\n\t\t\t\tUtilisateur[%d]:\n",i+1);
		printf("\t\t\t\tPrenom:%s\n",les_utilisateurs[i].Prenom);
		printf("\t\t\t\tNom:%s\n",les_utilisateurs[i].Nom);
		printf("\t\t\t\tId:%d\n",les_utilisateurs[i].numero);
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