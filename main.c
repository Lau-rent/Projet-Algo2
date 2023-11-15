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

    // int s1[4] = {3,-2};
    // int tab1[6] = {1,0,1,0,1,-2};
    // bool(f2(taille(tab1)-2,2,s1,tab1));

    printf("nbligne = %d\n", nbLigne("0.txt"));
    printf("nbcolonne = %d\n", nbColonne("0.txt"));

    
    char* string = "1 0 ";
    int* tab = convertStringtoTab(string, 7);
    afficherTab(tab);

  //  coloration("0.txt");
  test2();
    

    //int* tab = convertStringtoTab(string);
    //afficherTab(convertStringtoTab(string));
    
    return 0;
}