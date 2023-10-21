#include "fonction.h"

int main(){

    int s[5] = {1, 1, 2, 3, 1};

    printf("Test de T(J,L)\n");
    
    bool(T1_4(2, 0, s));
    bool(T1_4(2, 1, s));
    bool(T1_4(2, 2, s));
    bool(T1_4(2, 3, s));
    bool(T1_4(10, 4, s));
    bool(T1_4(10, 5, s));

    
    return 0;
}