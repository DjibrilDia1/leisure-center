#ifndef UTILISATEURS_H
#define UTILISATEURS_H
#define TAILLE_NOM 50
#define TAILLE_TEL 10

// structure pour le numero de telephone
struct Numero {
    char indicatif[TAILLE_TEL];
    int numero;
};

// structure pour les informations de l'utilisateur
struct User{
    char Prenom[TAILLE_NOM];
    char Nom[TAILLE_NOM];
    int numero;
    struct Numero tel;
};

// Ajouter des utilisateurs
void add_users(struct User les_utilisateurs[]);
// Afficher tous les utilisateurs
void display_users(struct User les_utilisateurs[]);
// Modifier un utilisateur
void mod_users(struct User les_utilisateurs[]);
// liberer la memoire allouee pour les utilisateurs
void free_users(struct User *les_utilisateurs);
// supprimer un utilisateur
void delete_user(struct User les_utilisateurs[]);

#endif // UTILISATEURS_H