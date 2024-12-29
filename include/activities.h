#ifndef ACTIVITIES_H
#define ACTIVITIES_H
#include "graph.h"

typedef struct Activity {
    char name[100]; // nom de l'activité
    char description[100]; // description de l'activité
    int id; // identifiant de l'activité(optionnel)
    struct Activity* next;
} Activity;

// ajoute une nouvelle activité à la liste
void add_activity(struct Activity** head, char* name);

// Function to remove an activity from the list
void remove_activity(struct Activity** head, char* name);

// Function to recommend activities based on user preferences
void recommend_activities(struct Activity* head, const char* preference);

#endif // ACTIVITIES_H