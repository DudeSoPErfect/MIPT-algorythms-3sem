#include <stdio.h>
#include <stdlib.h>



uint num_jumps(uint N, uint M) {
    uint* arr = (uint*)calloc(N, sizeof(uint));

    uint sum_m = 0;
    for (size_t i = 0; i < N; i++) {
        arr[i] = sum_m;
        if (i < M) 
            arr[i] += 1;
        
        sum_m += arr[i];
        if (i >= M) 
            sum_m -= arr[i - M];
        
    }
    free(arr);
    return arr[N-1];
}


int main() {

    uint N = 0, M = 0;
    scanf("%d %d", &N, &M);
    printf("%u\n", num_jumps(N, M));
    

    return 0;
}
