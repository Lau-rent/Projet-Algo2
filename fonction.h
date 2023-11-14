#ifndef Crabe
#define Crabe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T1_4(int j, int l, int* s);
void afficher(int j, int l, int *s);
void bool(int b);
int* convertTab(int *tab);
int compareTab(int* s, int* tab);
int* copieTab( int* tab);
int f2(int j , int l, int *s, int *tab);
int taille(int* tab);
void afficherTab(int* tab);
void coloration(char* file);
int* convertStringtoTab(char* string);

#endif