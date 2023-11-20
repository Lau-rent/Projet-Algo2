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
        printf("%d,\t", tab[i]);
    }
    printf("%d ", tab[size-2]);
    printf("]\n");
}

// int f2(int j , int l, int *s, int *tab){
//     //j = la taille de tab

//     if(j == -1){
//         return compareTab(s,tab);
//     }

//     if(tab[j] == -1 || tab[j] == 1){
//         return f2(j-1, l, s, tab);
//     }

//     if(tab[j] == 0){
//         int* copie1 = copieTab(tab);
//         int* copie2 = copieTab(tab);
//         copie1[j] = -1;
//         copie2[j] = 1;
//         return f2(j-1, l, s, copie1) || f2(j-1, l, s, copie2);
//     }
//     return 2;
// }

int f3(int j , int l, int *s, int *tab){
    //j = la taille de tab

    if(j == 0){
        int res = compareTabOpti(s,tab,l);
        //free(tab);
        return res;
    }

    if(tab[j] == -1 || tab[j] == 1){
        // free(s);
        // free(tab);
        return f3(j-1, l, s, tab);
    }

    if(tab[j] == 0){
        int* copie1 = copieTabOpti(tab, l);
        int* copie2 = copieTabOpti(tab, l);
        copie1[j] = -1;
        copie2[j] = 1;
        //free(tab);
        return f3(j-1, l, s, copie1) || f3(j-1, l, s, copie2);
    }
    return 2;
}

int f2(int j , int l, int *s, int *tab){
    if(l == 0){
        for(int i = 0; i < j; i++){
            if(tab[i] == 1){
                return 0;
            }
        }
        return 1;
    }

    if(j < s[l-1]-1){
        return 0;
    }

    if(j == s[l-1]-1){
        for(int i = 0; i <= j; i++){
            if(tab[i] == -1){
                return 0;
            }
        }
        if(tab[j+1] == 0 && j != N){
            return 0;
        }
        return 1;
    }

    if(tab[j] == -1){
        return f2(j-1, l, s, tab);
    }

    if(tab[j] == 1){
        for(int i = j - s[l-1] + 1; i < j; i++){
            if(tab[i] == -1){
                return 0;
            }
        }
      //  if(tab[j-s[l-1]] == 1){
        if(tab[j+1] == 1 && j != N-1){
            return 0;
        }
        return f2(j - s[l-1], l-1, s, tab);
    }

    if(tab[j] == 0){
        int bB;
        int bN1 = 1;
        int bN2 = 1;
        int bN3;

        bB = f2(j - 1, l, s, tab);

        for(int i = j - s[l-1]+1; i < j; i++){
            if(tab[i] == -1){
                bN1 = 0;
            }
        }
        if(tab[j+1] == 1){
            bN2 = 0;
        }
        bN3 = f2(j - s[l-1], l - 1, s, tab);
        printf("%d", bB);
        return  bB || (bN1 && bN2 && bN3);       
    }
    
    return 2;
}


int compareTabOpti(int* s, int* tab, int length){
    length += 2;
    
    int* copie = malloc(sizeof(int)*length);
    int j = convertTabOpti(tab, copie, length);


    for(int i = 0; i < j+2; i++){
        if(s[i] != copie[i]){
            //free(copie);
            //free(tab);
            return 0;
        }
    }
    //free(tab);
    //free(copie);
    return 1;
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

int* copieTabOpti(int* tab, int taille){
    taille+=2;
    int* copie = malloc(sizeof(int)*taille);
    for(int i = 0; i < taille-1; i++){
        copie[i] = tab[i];
    }
    copie[taille-1] = -2;
    //free(tab);
    return copie;
}

int compareTab(int* s, int* tab){
    int size = taille(s)-1;
    int* convertedTab = convertTab(tab);

    if(sommeTab(convertedTab) != sommeTab(s)){
        return 0;
    }
    for(int i = 0; i < size; i++){
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
        if(tab[i] != -1){
            somme += tab[i];
        }
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
            continue;
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

int convertTabOpti(int* tab, int* copie, int taille){
    int j = 0;
    for(int i = 0; i < taille-1; i++){
        if(tab[i] == 1){
            copie[j] += tab[i];
            continue;
        }
        if(tab[i] == 0 || tab[i] == -1){
            if(copie[j] != 0){
                j++;
            }
        }
    }
    copie[taille-1] = -2;
    //free(tab);
    return j;
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
    free(destination);
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
    free(destination);
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
    clock_t start, end;
    double temps_utiliser;

    start = clock();

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
    //LignesAVoir ← {0,...,N −1}
    for(int i = 0; i < nbligne; i++){
        listeLigne[i] = 1;
    }
    //ColonnesAVoir ← {0,...,M −1}
    for(int i = 0; i < nbcol; i++){
        listeCol[i] = 1;
    }
    listeLigne[nbligne] = -2;
    listeCol[nbcol] = -2;

    int boolL, boolC;

    while(sommeListe(listeLigne, nbligne) != 0 || sommeListe(listeCol, nbcol) != 0){
        for(int i = 0; i < nbligne; i++){
            if(listeLigne[i] == 0){
                continue;
            }
            boolL = est_coloriable_ligne(i, matrice, nbcol, tabLigne[i], listeCol);
            listeLigne[i] = 0; 
            
            if(boolL == 0){
                printf("Impossible Ligne %d\n", i);
                freeMatrice(tabLigne, nbligne);
                freeMatrice(tabCol, nbcol);
                free(destination);
                return matrice;
            }
        }
        for(int i = 0; i < nbcol; i++){
            if(listeCol[i] == 0){
                continue;
            }
            boolC = est_coloriable_colonne(i, matrice, nbligne, tabCol[i], listeLigne);
            listeCol[i] = 0;
       
            if(boolC == 0){
                printf("Impossible Colonne %d\n", i);
           //     freeMatrice(tabLigne, nbligne);
          //      freeMatrice(tabCol, nbcol);
          //      free(destination);
                return matrice;
            }
        }
    }

    end = clock();
    temps_utiliser = ((double) (end - start)) / CLOCKS_PER_SEC;

    afficheMatrice(matrice, nbligne);
    affichageVisuel(matrice, nbligne, nbcol, tabLigne, tabCol);
    printf("%s a pris: %f secondes pour être résolue\n",file, temps_utiliser);
 //   freeMatrice(tabLigne, nbligne);
 //   freeMatrice(tabCol, nbcol);
 //   free(destination);
    return matrice;
}

int sommeListe(int* liste, int taille){
    int somme = 0;
    for(int i=0; i<taille;i++){
        somme+=liste[i];
    }
    return somme;
}

int** creerMatrice(int nbLig, int nbCol){
    int **mat = (int**)malloc(sizeof(int*)*nbCol*nbLig);
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

int est_coloriable_ligne(int i, int** mat, int taille, int *seq, int* liste){
    for(int j = 0; j < taille; j++){
        if(mat[i][j] == -1 || mat[i][j] == 1 ){
            continue;
        }

        int* temp = malloc(sizeof(int)*(taille+1));
        temp[taille] = -2;
        int* temp2 = malloc(sizeof(int)*(taille+1));
        temp2[taille] = -2;
        for(int k = 0; k < taille; k++){
            temp[k] = mat[i][k];
        }

        temp[j] = -1;
        int boolB = f2(taille-1, taille-1, seq, temp);
        
        temp2[j] = 1;
        int boolN = f2(taille-1, taille-1, seq, temp2);

        // free(temp);
        // free(temp2);

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

int est_coloriable_colonne(int i, int** mat, int taille, int *seq, int* liste){
    for(int j = 0; j < taille; j++){
        int* temp = malloc(sizeof(int)*(taille+1));
        temp[taille] = -2;

        int* temp2 = malloc(sizeof(int)*(taille+1));
        temp2[taille] = -2;
        for(int k = 0; k < taille; k++){
            temp[k] = mat[k][i];
            temp2[k] = mat[k][i];

        }

        if(temp[j] == 1 || temp[j] == -1){
            // free(temp);
            // free(temp2);
            continue;
        }

        temp[j] = -1;
        int boolB = f2(taille-1, taille-1, seq, temp);
        
        temp2[j] = 1;
        int boolN = f2(taille-1, taille-1, seq, temp2);

        // if(temp != NULL){
        //         free(temp);
        //     }
        // if(temp2 != NULL){
        //         free(temp2);
        //     }

        if(boolN == 1 && boolB == 0){
            mat[j][i] = 1;
            liste[j] = 1;
        }
        if(boolN == 0 && boolB == 1){
            mat[j][i] = -1;
            liste[j] = 1;
        }
        if(boolN == 1 && boolB == 1){
            mat[j][i] = 0;
        }
        if(boolN == 0 && boolB == 0){;
            // free(temp);
            // free(temp2);
            return 0;
        }
    }
    return 1;
}

void freeMatrice(int** mat, int taille){
    for(int i = 0; i < taille; i++){
        free(mat[i]);
    }
    free(mat);
}

void afficheDessin(int* tab, int taille ){
    for(int i = 0; i < taille; i++){
        if(tab[i] == 1){
            printf("██");
            continue;
        }
        else if(tab[i] == -1){
            printf("░░");
            continue;
        }
    }
    printf("\n");
}

void afficheVertical(int* tab, int nbColonne){
    for(int i = 0; i < nbColonne/2; i++){
        if(tab[nbColonne/2-i-1] == 0){
            printf("  ");
        }
        else{
            printf("%d ", tab[nbColonne/2-i-1]);
        }
    }
    printf(" ");
}

void afficherHorizontal(int** tab, int nbLigne, int nbColonne){
    for(int i = 0; i < nbLigne; i++){
        for(int k = 0; k < nbColonne / 2; k++){
            printf("  ");
        }
        printf(" ");
        for(int j = 0; j < nbColonne; j++){
            if(tab[j][nbLigne-i-1] == 0){
                printf("  ");
            }
            else{
                printf("%d ", tab[j][nbLigne-i-1]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void affichageVisuel(int** mat, int nbLigne, int nbColonne, int** tabLigne, int** tabCol){
    afficherHorizontal(tabCol, nbLigne, nbColonne);
    for(int i = 0; i < nbLigne; i++){
        afficheVertical(tabLigne[i], nbColonne);

        afficheDessin(mat[i], nbColonne);
    }
    printf("\n");
}