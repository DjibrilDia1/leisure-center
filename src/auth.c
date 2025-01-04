#include <stdio.h>
#include <string.h>
#include "auth.h"

int authenticate(char* username, char* password) {
    // Simple authentication for demonstration
    if (strcmp(username, "admin") == 0 && strcmp(password, "passer") == 0) {
        return ROLE_ADMIN;
    } 
    else if (strcmp(username, "user") == 0 && strcmp(password, "user123") == 0) {
        return ROLE_USER;
    }
    return 0;
}

