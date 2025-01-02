#ifndef UTILISATEURS_H
#define UTILISATEURS_H
#define TAILLE_NOM 50
#define TAILLE_TEL 10

// structure pour la date de naissance
struct Date_de_naissance {
    int jour;
    int mois;
    int annee;
};

// structure pour l'adresse
struct Adresse {
    char Rue[TAILLE_NOM];
    char ville[TAILLE_NOM];
    int numero;
};

// structure pour le numero de telephone
struct Numero {
    char indicatif[TAILLE_TEL];
    int numero;
};

// structure pour les informations de l'utilisateur
struct User{
    char Prenom[TAILLE_NOM];
    char Nom[TAILLE_NOM];
    int numero_etudiant;
    struct Date_de_naissance date;
    struct Adresse adresse;
    struct Numero numero;
};

// Ajouter des utilisateurs
void add_users(struct User les_utilisateurs[]);
// Afficher tous les utilisateurs
void display_users(struct User les_utilisateurs[]);
// Modifier un utilisateur
void mod_users(struct User *les_utilisateurs,int *taille);

#endif // UTILISATEURS_H