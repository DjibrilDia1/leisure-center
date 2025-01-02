#include <stdio.h>
#include "users.h"

// Taille du tableau d'utilisateurs
int taille = 0;

void saisirDate(struct Date_de_naissance *s) {
    // Contrôle de saisie pour le jour
    printf("\n\t\t\t\t\tJour (1-31): ");
    while (scanf("%d", &s->jour) != 1 || s->jour < 1 || s->jour > 31) {
        getchar();// en cas de saisie incorrect
        printf("\t\tJour invalide. Reessayer (1-31): ");
    }

    // Contrôle de saisie pour le mois
    printf("\t\t\t\t\tMois (1-12): ");
    while (scanf("%d", &s->mois) != 1 || s->mois < 1 || s->mois > 12) {
        getchar(); // en cas de saisie incorrect
        printf("\t\t\tMois invalide. Reessayer (1-12): ");
    }

    // Contrôle de saisie pour l'année
    printf("\t\t\t\t\tAnnee (192-2025): ");
    // controle de saisie sur scanf pour verifier qu'il a bien entre un nombre
    while (scanf("%d", &s->annee) != 1 || s->annee < 1924 || s->annee > 2012) {
        getchar();// en cas de saisie incorrect
        printf("\t\tAnnee invalide. Reessayer (1924-2012): ");
    }
}

/*
    name: saisirAdresse
    parametres: 1
    return value: NULL
    created by: Djibril Dia
	description: Cette fonction nous sert a recupérer les informations de l'adresse de l'utilisateur   
 */

void saisirAdresse(struct Adresse *s) {
    // Saisie de la rue
    printf("\n\t\t\t\t\tRue: ");
    scanf("%s", s->Rue);

    // Saisie de la ville
    printf("\t\t\t\t\tVille: ");
    scanf("%s", s->ville);

    // Contrôle de saisie du numéro d'adresse
    printf("\t\t\t\t\tNumero: ");
    while (scanf("%d", &s->numero) != 1 || s->numero <= 0) {
        getchar();// Vider le buffer d'entrée
        printf("\t\t\t\t\tNumero invalide. Reessayer: ");
    }
}

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
    printf("\n\t\tEntrer votre Nom:");
    scanf("%s", et->Nom);
    // Saisie du numero de l'utilisateur
    printf("\t\t\t\t\tEntrer l'ID:");
	scanf("%d", &et->numero_etudiant);
	// controle de saisie
	while(!et->numero_etudiant){
		getchar();
		printf("\n\t\t\t\t\tinvalide,Reessayer:");
		scanf("%d", &et->numero_etudiant);
	}
	// Saisie de la date de naissance
    printf("\n\t\t\t\tEntrer la Date de naissance:");
    saisirDate(&et->date);
    // Saisie de l'adresse
    printf("\n\t\t\t\tEntrer l'adresse:");
    saisirAdresse(&et->adresse);
    // Saisie du numero de telephone
    printf("\n\t\t\t\tEntrer le numero de telephone:");
    saisirtel(&et->numero);    
    printf("\n\t\t\t\t-> L'utilisateur a ete cree !\n");
}

// Fonction pour ajouter un utilisateur
/*
    name: Ajouter des utilisateurs
    return value: NULL
    created by: Djibril Dia
    description: Cette fonction nous sert a recupérer les informations de l'utilisateur 
*/
void add_users(struct User les_utilisateurs[]){
    // Saisie des informations de l'utilisateur
    saisir_utilisateur(&les_utilisateurs[taille]);
    // A chaque creation d'un nouveau etudiant , la taille augmente
    taille++;
}

void display_users(struct User les_utilisateurs[]){
    // Affichage des informations de l'utilisateur
    int i;
    for(i=0;i<taille;i++){
        printf("\n\t\t\t\tUtilisateur[%d]:\n",i+1);
		printf("\t\t\t\tPrenom:%s\n",les_utilisateurs[i].Prenom);
		printf("\t\t\t\tNom:%s\n",les_utilisateurs[i].Nom);
		printf("\t\t\t\tId:%d\n",les_utilisateurs[i].numero_etudiant);
		printf("\t\t\t\tNee le %d/%d/%d\n",les_utilisateurs[i].date.jour,les_utilisateurs[i].date.mois,les_utilisateurs[i].date.annee);
		printf("\t\t\t\tAdresse:%d,%s,%s\n",les_utilisateurs[i].adresse.numero,les_utilisateurs[i].adresse.Rue,les_utilisateurs[i].adresse.ville);	
	}
}

void mod_users(struct User *les_utilisateurs,int *taille){
    // Modification des informations de l'utilisateurS
}