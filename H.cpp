#include <iostream>
#include <cstdlib>
#include <limits.h>

uint square(uint x) {
    return x * x; 
}

void make_values_max(uint* values, uint length) {
    for (size_t i = 1; i < length; i++) {
        values[i] = UINT_MAX;
    }
}

uint calc_results(uint* values, uint length) {
    for (size_t i = 1; i < length; i++) {
        for(size_t j = 1; square(j) <= i; j++) {
            uint check_prev = i - square(j);
            if (check_prev == 0)
                values[i] = 1;
            else
                if (values[check_prev] + 1 < values[i])
                    values[i] = values[check_prev] + 1;
         }
    }

    return values[length - 1];
}


uint simple_dp(uint num) {
    uint* values = new uint[num]();
    
    make_values_max(values, num);
    uint answer = calc_results(values, num);

    delete [] values;
    return answer;

}



int main() {

    uint num = 0;
    std::cin >> num;
    std::cout << simple_dp(++num);

    return 0;

}
