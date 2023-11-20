#ifndef Crabe
#define Crabe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5 


//Partie 1,1
int f1(int j, int l, int* s);
void afficher(int j, int l, int *s);
void bool(int b);

//Partie 1,2
int sommeTab(int* tab);
int* convertTab(int *tab);
int compareTab(int* s, int* tab);
int* copieTab( int* tab);
int f2(int j , int l, int *s, int *tab);
int taille(int* tab);
void afficherTab(int* tab);
int compareTabOpti(int* s, int* tab, int length);
int convertTabOpti(int* tab, int* copie, int taille);
int* copieTabOpti(int* tab, int taille);
int f3(int j , int l, int *s, int *tab);
//Partie 1,3
int nbLigne(char* file);
int nbColonne(char* file);
int** coloration(char* file);
int* convertStringtoTab(char* string, int size);
void afficheMatrice(int** mat, int nbLigne );
void test(char * file);
void test2();
int est_coloriable_ligne(int i, int** mat, int taille, int *seq, int* liste);
int sommeListe(int* tab, int taille);
int est_coloriable_colonne(int i, int** mat, int taille, int *seq, int* liste);
int** creerMatrice(int nbLig, int nbCol);
void freeMatrice(int** mat, int taille);

//Affichage
void afficheDessin(int* tab, int taille );
void afficheVertical(int* tab, int nbColonne);
void affichageVisuel(int** mat, int nbLigne, int nbColonne, int** tabLigne, int** tabCol);
void afficherHorizontal(int** tab, int nbLigne, int nbColonne);
#endif