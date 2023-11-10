#include "fonction.h"

//T(j,l) pour la question 4, partie 1,1

int T1_4(int j, int l, int* s){
    afficher(j, l, s);
    if(l == 0){
        return 1;
    }

    if(l >= 1){
        if(j < s[l-1]){
            return 0;
        }
        if(j >= s[l-1]){
            if(l == 1){
                return T1_4(j-s[l-1], l-1, s);
            }
            else{
                return T1_4(j-s[l-1]-1, l-1, s);
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

void afficherTab(int* tab){
    printf("tab = [ ");
    for(int i = 0; i < taille(tab); i++){
        printf("%d ", tab[i]);
    }
    printf("]\n");
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

int f2(int j , int l, int *s, int *tab){
    //j c'est la taille de tab

    if(j == 0){
        afficherTab(tab);
        printf("taille %d\n",taille(tab));
        return compareTab(s,tab);
    }

    int* copie1 = copieTab(tab);
    int* copie2 = copieTab(tab);

    if(tab[j] == 1){
        return f2(j-1, l, s, tab);
    }

    else{
        copie1[j] = 0;
        copie2[j] = 1;
        return f2(j-1, l, s, copie1) || f2(j-1, l, s, copie2);
    }
}

int* copieTab(int* tab){
    int size = taille(tab);
    int* copie = malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        copie[i] = tab[i];
    }
    return copie;
}

int compareTab(int* s, int* tab){
    int size = taille(tab);

    for(int i = 0; i < size; i++){
        if(s[i] != tab[i]){
            return 0;
        }
    }
    return 1;
}

int* convertTab(int* tab){
    int size = taille(tab);
    int* copie = malloc(sizeof(int)*size);
    int j = 0;
    for(int i = 0; i < size; i++){
        if(tab[i] == 1){
            copie[j] += tab[i];
        }
        if(tab[i] == 0){
            if(copie[j] != 0){
                j++;
            }
        }
    }
    return copie;
}

int taille(int* tab){
    int size = 0;
    while (tab[size] != '\0') {
        size++;
    }
    return size;
}