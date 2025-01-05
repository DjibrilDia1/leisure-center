## Système de Gestion d'un Centre de Loisirs

## Description
Application de gestion d'activités pour un centre de loisirs permettant:
- Gestion des activités (ajout, suppression, modification)
- Gestion des utilisateurs
- Système de recommandation d'activités
- Interface administrateur 

## Prérequis
- GCC (GNU Compiler Collection)
- Make (optionnel)
- Windows ou Linux

## Installation

### Windows
```bash
# Compiler le projet
gcc main.c src/* -o main -Iinclude

# Exécuter le programme
./main.exe && rm main.exe 
```

## Utilisation

### Connexion
    * Admin:
        - Username: admin
        - Password: passer

### Menu Principal
    1.Gestion des activités
        ->Ajouter une activité
        ->Afficher les activités
        ->Connecter des activités
        ->Supprimer une activité
        ->Gestion des utilisateurs

        ->Ajouter un utilisateur
        ->Afficher les utilisateurs
        ->Modifier un utilisateur
        ->Supprimer un utilisateur

    2.Gestion des utilisateurs
        Ajouter un utilisateur
        Afficher les utilisateurs
        Modifier un utilisateur
        Supprimer un utilisateur

## Structure du projet
projet/
├── include/
│   ├── activities.h
│   ├── admin_and_users.h
│   ├── auth.h
│   ├── graph.h
│   ├── menu.h
│   ├── users.h
│   └── utils.h
├── src/
│   ├── activities.c
│   ├── admin_and_users.c
│   ├── auth.c
│   ├── graph.c
│   ├── main.c
│   ├── menu.c
│   ├── users.c
│   └── utils.c
|
|── main.c
|
└── README.md

## Auteur
    - Djibril Dia

## License
Ce projet est sous licence MIT ``` 