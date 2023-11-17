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

	int s1[6] = {3,0,0,0,0,-2};
	int tab1[6] = {1,0,0,0,0,-2};
	bool(f2(taille(tab1)-2,2,s1,tab1));







	int** matrice = coloration("0.txt");
	afficheMatrice(matrice, 4);





	return 0;
}