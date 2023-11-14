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
    int size = taille(tab);
    for(int i = 0; i < size-2; i++){
        printf("%d, ", tab[i]);
    }
    printf("%d ", tab[size-2]);
    printf("]\n");
}

void bool(int b){
    if(b == 1){
        printf(":D Vrai\n\n");
    }
    if(b == 0){
        printf(":C Faux\n\n");
    }
    if(b != 0 && b != 1){
        printf("xP Erreur\n\n");
    }

}

int f2(int j , int l, int *s, int *tab){
    //j c'est la taille de tab

    if(j == 0){
        return compareTab(s,tab);
    }

    if(tab[j] == -1 || tab[j] == 1){
        return f2(j-1, l, s, tab);
    }

    if(tab[j] == 0){
        int* copie1 = copieTab(tab);
        int* copie2 = copieTab(tab);
        copie1[j] = -1;
        copie2[j] = 1;
        return f2(j-1, l, s, copie1) || f2(j-1, l, s, copie2);
    }
    return 2;
}

int* copieTab(int* tab){
    int size = taille(tab);
    int* copie = malloc(sizeof(int)*size);
    for(int i = 0; i < size-1; i++){
        copie[i] = tab[i];
    }
    copie[size-1] = -2;
    return copie;
}

int compareTab(int* s, int* tab){
    int size = taille(s)-1;
    int* convertedTab = convertTab(tab);

    for(int i = 0; i < size; i++){
        if(s[i] != convertedTab[i]){
            return 0;
        }
    }
    if(convertedTab[size] != 0){
        return 0;
    }
    afficherTab(tab);
    return 1;
}

int* convertTab(int* tab){
    int size = taille(tab);
    int* copie = malloc(sizeof(int)*size);
    int j = 0;
    for(int i = 0; i < size-1; i++){
        if(tab[i] == 1){
            copie[j] += tab[i];
        }
        if(tab[i] == 0 || tab[i] == -1){
            if(copie[j] != 0){
                j++;
            }
        }
    }
    copie[size-1] = -2;
    return copie;
}

int taille(int* tab){
    int size = 0;
    while(tab[size] != -2){
        size++;
    }
    return size+1;
}

// void coloration(char* file){
//     FILE *f;
//     char buffer[255];
//     f = fopen(file, "r");
//     int* tab;
//     int size = -1;
//     while (fgets(buffer, sizeof(buffer), f) != NULL) {
//         size++;
//         if (buffer[0] == '#') {
//             break;
//         }
//     }
//     fclose(f);
//     printf("size = %d\n", size);
//     FILE *f2;
//     f2 = fopen(file, "r");
//     int** tab = (int**)malloc(sizeof(int)*size*size);
//     while (fgets(buffer, sizeof(buffer), f2) != NULL) {
        
//         printf("%s", buffer);
//     }

//     fclose(f2);
// }

// int* convertStringtoTab(char* string, int tailleTab){

//     int size = 0;
//     while(string[size] != '\0'){
//         size++;
//     }
//     int* tab = malloc(sizeof(int)*tailleTab);
//     int count = 0;

//     char* res = malloc(sizeof(char)*size);
//     char tmp;
//     char vide = ' ';
//     for(int i=0; string[i] != '\0'; i++){
//         printf("caract = %c\n", string[i]);
//         tmp = string[i];
//         if(strcmp(&tmp, &vide) != 0){
//             res = strcat(res, &tmp);
//             printf("%s\n", res);
//         }
//         if(strcmp(&tmp, &vide) == 0){
//             tab[count] = atoi(res);
//             count++;
//             printf("reset\n");
//             strcat(res, "");
//         } 
//     }
//     return tab;
// }


int* convertStringtoTab(char* str) {
    
    while (strcmp(str, '\0') == 0) {
        if (strcmp(str, " ") == 0) {
            *str = '\0';
        }
        str++;
    }
