#include "fonction.h"

//T(j,l) pour la question 4, partie 1,1

int T1_4(int j, int l, int* s){
    if(l == 0){
        afficher(j, l, s);
        return 1;
    }

    if(l >= 1){
        if(j < s[l-1]){
            return 0;
        }
        if(j == s[l-1]){
            if(l-1 == 0){
                afficher(j, l, s);
                return T1_4(j-s[l], l-1, s);
            }
            else{
                afficher(j, l, s);
                return T1_4(j-s[l]-1, l-1, s);
            }
        }
        if(j > s[l-1]){
            if(l-1 == 0){
                afficher(j, l, s);
                return T1_4(j-s[l], l-1, s);
            }
            else{
                afficher(j, l, s);
                return T1_4(j-s[l]-1, l-1, s);
            }
        }
    }
    return 2;
}

void afficher(int j, int l, int* s){
    printf("j = %d, l = %d, s = { ",j ,l );
    for(int i = 0; i < l - 1; i++){
        printf("%d, ", s[i]);
    }
    printf("%d }\n", s[l-1]);
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