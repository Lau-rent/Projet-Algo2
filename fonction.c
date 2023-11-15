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
    printf("tab = [ ");
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
    char *token;
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

void coloration(char* file){
    FILE *f;
    char buffer[255];
    f = fopen(file, "r");

    int nbligne = nbLigne(file);
    int nbcol = nbColonne(file);

    int i = 0;
    int** tabLigne = (int**)malloc(sizeof(int)*nbcol*nbligne);
    
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (buffer[0] == '#'){
            break;
        }
        tabLigne[i] = convertStringtoTab(buffer, nbcol);
        afficherTab(convertStringtoTab(buffer, nbcol));
        i++;
    }

    i = 0;
    int** tabCol = (int**)malloc(sizeof(int)*nbcol*nbligne);
    while (fgets(buffer, sizeof(buffer), f) != NULL){
        tabCol[i] = convertStringtoTab(buffer, nbligne);
        i++;
    }

    fclose(f);
    int tabvideligne[nbligne][nbcol];
    int res;
    for(int i=0; i<nbligne;i++){
        res = f2(nbcol,0,conv,tabvideligne[i]);
        if(res == 0){
            return;
        }

    }



}

void test(char* file){
    FILE *f;
    char buffer[255];
    f = fopen(file, "r");
    
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
 
int** creerMatrice(int pos, int nbLig, int nbCol){
    int **mat = (int**)malloc(sizeof(int*)*nbCol*nbLig);
    return mat;
}

void matAjout(int** mat, int* tab, int pos){
    mat[pos] = tab;
}


void afficheMatrice(int** mat, int taille){
    for(int i = 0; i < taille; i++){
        afficherTab(mat[i]);
    }
}

void test2(){

char chaine[] = "1 22\n3\n4";
int tab[5][5];
int index = 0;


   char *token = strtok(chaine, "\n"); 
    while (token != NULL && index < 20) {
        char* espace = strchr(token, ' '); 
        if (espace != NULL) {
            *espace = '\0'; 

            tab[index][0] = atoi(token); 
            tab[index][1] = atoi(espace + 1); 
        } else {
            tab[index][0] = atoi(token); 
            tab[index][1] = 0; 
        }
        index++;
        token = strtok(NULL, "\n");
        tab[index][4] = -2;
    }
printf("Tableau de tableaux d'entiers :\n");
    for (int i = 0; i < index; i++) {
        if (tab[i][1] != 0) {
            printf("{%d,%d}", tab[i][0], tab[i][1]);
        } else {
            printf("{%d}", tab[i][0]);
        }
        afficherTab(tab[i]);
    }

printf("\n");
}

int est_coloriable(int i, int j, int** mat){
    if(mat[i][j] == 0){
        
    }
}
