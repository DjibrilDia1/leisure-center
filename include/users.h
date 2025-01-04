#ifndef UTILISATEURS_H
#define UTILISATEURS_H
#define TAILLE_NOM 50
#define TAILLE_TEL 10
# include "graph.h"
# include "activities.h"

// structure pour le numero de telephone
struct Numero 
{
    char indicatif[TAILLE_TEL];
    int numero;
};

struct UserActivity
{
    int activity_id; // id de l'activité
    struct Activity *activity; // pointeur vers l'activité
    struct UserActivity *next; // pointeur vers l'activité suivante
};


// structure pour les informations de l'utilisateur
struct User
{
    char Prenom[TAILLE_NOM];
    char Nom[TAILLE_NOM];
    int numero;
    struct Numero tel;
    struct UserActivity *activities; // liste des activités de l'utilisateur
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
// Ajouter une activité à un utilisateur
void add_user_activities(struct User les_utilisateurs[],struct Graph **graph);

#endif // UTILISATEURS_H