#include "fonction.h"

int main(){

	/*
	int s[5] = {1, 1, 2, 3, 1};
	int s2[1] = {1};

	printf("Test de T(J,L)\n\n");

	bool(f1(2, 0, s));
	bool(f1(2, 1, s));
	bool(f1(2, 2, s));
	bool(f1(2, 3, s));
	bool(f1(10, 4, s));
	bool(f1(10, 5, s));

	bool(f1(0, 1, s2));

	bool(f1(3,1,s2));
	*/
	// printf("-1 = blanc, 0 = vide, 1 = noir\n\n");
	// int s[2] = {3};
	// int tab[5] = {0,1,0,1,0};
	// bool(f2(4,1,s,tab));

	// int s1[6] = {1,1,1,-2};
	// int* tab1 = malloc(sizeof(int)*6);
	// tab1[0] = 0;
	// tab1[1] = 1;
	// tab1[2] = 0;
	// tab1[3] = 1;
	// tab1[4] = 0;
	// tab1[5] = -2;

	// bool(f3(taille(tab1)-2,taille(tab1)-2,s1,tab1));
	int s2[2] = {1,2};
	int tab2[5] = {1,1,1,-1,0};
	bool(f2(4,2,s2,tab2));
	bool(f3(3,2,s2,tab2));







//	afficheMatrice(coloration("0.txt"), 4);
	// int taille = nbLigne("1.txt");
	// int** matrice = coloration("1.txt");
	// freeMatrice(matrice, taille);
	// coloration("0.txt");
	// coloration("2.txt");
	
	return 0;
}