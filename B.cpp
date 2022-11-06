#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int* scan_arr(int len) {
    int* arr = (int*)calloc(len, sizeof(int));
    for (size_t i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}


int mod_min(int a, int b) {
     //   printf("%d %d\n", a, b);
    //printf("%d\n",(a <= b) && (a != 0) ? a : b);
    return (a <= b) && (a != 0) ? a : b; 
}

int mod_max(int a, int b) {
    return a >= b ? a : b;
}


int coins(int N, int S, int* nominals) {
    int* cash1 = (int*) calloc(S + 1, sizeof(int));
    int* cash2 = (int*) calloc(S + 1, sizeof(int));

    for (size_t i = 1; i < S + 1; i++) {
        cash1[i] = INT_MAX;
    }

    for (size_t i = 0; i < S + 1; i++) {
        if (cash1[i] == INT_MAX) 
            continue;

        for (size_t j = 0; j < N; j++) {
            if (nominals[j] + i < S + 1) {
                if (cash1[i] + 1 < cash1[nominals[j] + i]) {
                    cash1[nominals[j] + i] = cash1[i] + 1;
                    cash2[nominals[j] + i] = i;
                }
            }
            /*
            if (i + 1 == nominals[j]) {
                cash1[i] = 1;
                cash2[i] = nominals[j];
                break;
            } else if ((int) i - nominals[j] >= 0) {
                    //printf("cash1[%ld] = %d, nominals[j] = %d\n", i,cash1[i], nominals[j]);
                if (cash1[i - nominals[j]] == 0 && cash1[i] == 0) {
                    cash1[i] = 0;
                    cash2[i] = 0;
                } else if (cash1[i - nominals[j]] != 0){
                    cash1[i] = mod_min(cash1[i], cash1[i - nominals[j]] + 1);
                    cash2[i] = mod_max(nominals[j], cash2[i]);
                    //printf("cash1[%ld] = %d, nominals[j] = %d\n", i,cash1[i], nominals[j]);
                
                }
                
            }
            */
        }
    }    

 /*   
    for (size_t i = 0; i < S; i++) {
        printf("%d ", cash1[i]);
    }

    printf("\n");

    for (size_t i = 0; i < S; i++) {
        printf("%d ", cash2[i]);
    }

    printf("\n");    
*/


    int k = S;
    cash1[k] == 0 ? printf("%d\n", -1) : printf("%d\n", cash1[k]);
    while (k > 0) {
        printf("%d ", k - cash2[k]);
        k = cash2[k];
    }


    free(cash1);
    free(cash2);
}



int main() {
    int N = 0, S = 0;

    scanf("%d", &N);
    int* nominals = scan_arr(N);
    scanf("%d", &S);


    coins(N, S, nominals);
    free(nominals);
    return 0;
}
