#include "utils.h"
#include <windows.h> // pour utiliser system("cls") sur Windows
#include <stdio.h>

// fonction pour effacer l'écran
void clear_screen() {
#ifdef _WIN32
    system("cls"); // clear system pour windows
#endif
}

// fonction pour attendre une touche
void wait_for_keypress(){
    printf("\n\nAppuyez sur une touche pour continuer...");
    getchar();
    getchar();
}
