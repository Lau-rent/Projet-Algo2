#include "fonction.h"

//T(j,l) pour la question 4, partie 1,1

int T1_4(int j, int l, int* s){
    int somme = 0;

    for(int i = 0; i < l; i++){
        somme += s[i];
    }

    afficher(s, l);
    printf("L = %d, J = %d, Somme S = %d\n", l, j, somme);

    if(somme == 0){
        return 1;
    }

    if(somme -1 == j){
        return 1;
    }

    if(somme -1 > j){
        return 0;
    }

    if(somme -1 < j){
        return 1;
    }

    return 2;
}

void afficher(int* s, int l){
    printf("s = { ");
    for(int i = 0; i < l; i++){
        printf("%d ", s[i]);
    }
    printf("}\n");
}

void bool(int b){
    if(b == 1){
        printf("Vrai\n\n");
    }
    else if(b == 0){
        printf("Faux\n\n");
    }
    else{
        printf("Erreur\n\n");
    }
}