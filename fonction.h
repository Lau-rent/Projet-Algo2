#ifndef Crabe
#define Crabe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Partie 1,1
int T1_4(int j, int l, int* s);
void afficher(int j, int l, int *s);
void bool(int b);

//Partie 1,2
int* convertTab(int *tab);
int compareTab(int* s, int* tab);
int* copieTab( int* tab);
int f2(int j , int l, int *s, int *tab);
int taille(int* tab);
void afficherTab(int* tab);

//Partie 1,3
int nbLigne(char* file);
int nbColonne(char* file);
void coloration(char* file);
int* convertStringtoTab(char* string, int size);

#endif