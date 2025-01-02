#ifndef UTILS_H
#define UTILS_H

// Input validation for menu choices (1-10)
void control_saisie1(int *choix);

// Input validation for yes/no choices (0-1) 
void control_saisie(int *choix);

// Screen utilities
void clear_screen();
void wait_for_keypress();

#endif