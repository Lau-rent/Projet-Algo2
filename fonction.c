#include "fonction.h"

//Partie 1,1

int f1(int j, int l, int* s){
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
                return f1(j-s[l-1], l-1, s);
            }
            else{
                return f1(j-s[l-1]-1, l-1, s);
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
        printf(":D Vrai\n\n");
    }
    if(b == 0){
        printf(":C Faux\n\n");
    }
    if(b != 0 && b != 1){
        printf("xP Erreur\n\n");
    }

}

//Partie 1,2


void afficherTab(int* tab){
    printf("[ ");
    int size = taille(tab);
    for(int i = 0; i < size-2; i++){
        printf("%d, ", tab[i]);
    }
    printf("%d ", tab[size-2]);
    printf("]\n");
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

    if(sommeTab(convertedTab) != sommeTab(s)){
            return 0;
        }

    for(int i = 0; i < size; i++){
        if(s[i] == 0){
            continue;
        }
        if(s[i] == -2){
            break;
        }
        if(s[i] != convertedTab[i]){
            return 0;
        }
    }
    
    return 1;
}

int sommeTab(int* tab){
    int size = taille(tab);
    int somme = 0;
    for(int i = 0; i < size-1; i++){
        somme += tab[i];
    }
    return somme;
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

//Partie 1,3

int nbLigne(char* file){
    FILE *f;
    char buffer[255];
    char* destination = malloc(sizeof(char)*25);
    strcat(destination, "instances/");
    strcat(destination, file);
    f = fopen(destination, "r");
    int size = -1;
    while (fgets(buffer, sizeof(buffer), f) != NULL){
        size++;
        if (buffer[0] == '#'){
            break;
        }
    }

    fclose(f);
    return size;
}

int nbColonne(char* file){
    FILE *f;
    char buffer[255];
    char* destination = malloc(sizeof(char)*25);
    strcat(destination, "instances/");
    strcat(destination, file);
    f = fopen(destination, "r");
    int size = 0;
    while (fgets(buffer, sizeof(buffer), f) != NULL){
        if (buffer[0] == '#'){
            break;
        }
    }

    while (fgets(buffer, sizeof(buffer), f) != NULL){
        size++;
    }

    fclose(f);
    return size;
}

int* convertStringtoTab(char* string, int tailleTab){
    int* tab = (int*) malloc(sizeof(int)*(tailleTab+1));

    if (tab == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    char* str = strdup(string);
    char* token;
    int i = 0;

    token = strtok(str, " ");
    while( token != NULL ){
        tab[i] = atoi(token);
        i++;

        token = strtok(NULL, " ");
    }

    free(str);
    tab[tailleTab] = -2; //sentinelle de fin de tableau
    return tab;
}

int** coloration(char* file){
    FILE *f;
    char buffer[255];
    char* destination = malloc(sizeof(char)*25);
    strcat(destination, "instances/");
    strcat(destination, file);
    f = fopen(destination, "r");

    int nbligne = nbLigne(file);
    int nbcol = nbColonne(file);

    int i = 0;
    int** tabLigne = (int**)malloc(sizeof(int*)*nbcol*nbligne);
    
    //On récupère les lignes
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (buffer[0] == '#'){
            break;
        }
        tabLigne[i] = convertStringtoTab(buffer, nbcol);
        i++;
    }

    //On récupère les colonnes
    i = 0;
    int** tabCol = (int**)malloc(sizeof(int)*nbcol*nbligne);
    while (fgets(buffer, sizeof(buffer), f) != NULL){
        tabCol[i] = convertStringtoTab(buffer, nbligne);
        i++;
    }

    fclose(f);

    int** matrice = creerMatrice(nbligne, nbcol);

    int listeLigne[nbligne+1];
    int listeCol[nbcol+1];
    for(int i = 0; i < nbligne; i++){
        listeLigne[i] = 1;
    }
    for(int i = 0; i < nbcol; i++){
        listeCol[i] = 1;
    }
    listeLigne[nbligne] = -2;
    listeCol[nbcol] = -2;

    int boolL, boolC;

    while(listeEstVide(listeLigne, nbligne) != 0 || listeEstVide(listeCol, nbcol) != 0){
        for(int i = 0; i < nbligne; i++){
            if(listeLigne[i] == 0){
                break;
            }
            boolL = est_coloriable(i, matrice, nbcol, tabLigne[i], listeCol);
            listeLigne[i] = 0;
            if(boolL == 0){
                printf("Impossible Ligne %d\n", i);
                return matrice;
            }
        }

        for(int i = 0; i < nbcol; i++){
            if(listeCol[i] == 0){
                break;
            }
            boolC = est_coloriable(i, matrice, nbcol, tabCol[i], listeLigne);
            listeCol[i] = 0;
            if(boolC == 0){
                printf("Impossible Colonne %d\n", i);
                return matrice;
            }
        }
    }
    return matrice;
}

int listeEstVide(int* liste, int taille){
    int somme = 0;
    for(int i=0; i<taille;i++){
        somme++;
    }
    return somme;
}

void test(char* file){
    FILE *f;
    char buffer[255];
    char* destination = malloc(sizeof(char)*25);
    strcat(destination, "instances/");
    strcat(destination, file);
    f = fopen(destination, "r");
    
    int nbligne = nbLigne(file);
    int nbcol = nbColonne(file);

    int** tabLigne = (int**)malloc(sizeof(int)*nbcol*nbligne);
    int i = 0;
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (buffer[0] == '#'){
            break;
        }
        tabLigne[i] = convertStringtoTab(buffer, nbcol);
    }

    int** tabCol = (int**)malloc(sizeof(int)*nbcol*nbligne);
    while (fgets(buffer, sizeof(buffer), f) != NULL){
        tabCol[i] = convertStringtoTab(buffer, nbligne);
    }

    fclose(f);
}
 
int** creerMatrice(int nbLig, int nbCol){
    int **mat = (int**)malloc(sizeof(int*)*nbCol*nbLig+30);
    for(int i = 0; i < nbLig; i++){
        mat[i] = convertStringtoTab("0", nbCol);
    }
    return mat;
}

void afficheMatrice(int** mat, int taille){
    for(int i = 0; i < taille; i++){
        afficherTab(mat[i]);
    }
    printf("\n");
}

int est_coloriable(int i, int** mat, int taille, int *seq, int* liste){
    mat[i][taille] = -2; 
    for(int j = 0; j < taille; j++){
        mat[i][j] = -1;
        int boolB = f2(taille-1, 0, seq, mat[i]);
        mat[i][j] = 1;
        int boolN = f2(taille-1, 0, seq, mat[i]);
        if(boolN == 1 && boolB == 0){
            mat[i][j] = 1;
            liste[j] = 1;
        }
        if(boolN == 0 && boolB == 1){
            mat[i][j] = -1;
            liste[j] = 1;
        }
        if(boolN == 1 && boolB == 1){
            mat[i][j] = 0;
        }
        if(boolN == 0 && boolB == 0){
            return 0;
        }
    }
    return 1;
}
