#include <stdio.h>
#include <stdlib.h>

int comp(const int *i, const int *j) {
    return *i - *j;
}


int min(int x, int y) {
    return x >= y ? y : x;
}


int ropes(int N, int* arr) {

    if (N == 2)
        return arr[1] - arr[0];
    else if (N == 3)
        return arr[2] - arr[1] + arr[1] - arr[0];
    else if (N == 4)
        return arr[3] - arr[2] + arr[1] - arr[0];
    else {
        int* lens = (int*)calloc(N, sizeof(int));
        int* nums_con = (int*)calloc(N, sizeof(int));

        lens[0] = arr[1] - arr[0];
        lens[1] = arr[2] - arr[1] + arr[1] - arr[0];
        lens[2] = arr[3] - arr[2] + arr[1] - arr[0];
        for (size_t i = 3; i < N - 1; i++) {
            lens[i] = min(lens[i-2], lens[i-1]) + arr[i+1] - arr[i];
        }

        printf("%d\n", lens[N-2]);

        free(lens);
    }



}


int main() {

    uint N = 0;
    scanf("%u", &N);
    int* arr = (int*)calloc(N, sizeof(int));
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, N, sizeof(int), (int(*) (const void *, const void *)) comp);

    ropes(N, arr);



    free(arr);
    return 0;
}
