#include <iostream>
#include <cstdlib>
#include <cmath>


void winner(uint N) {
    bool* positions = new bool[N+1];

    positions[1] = true;
    for (size_t pos = 2; pos <= N; pos++) {
        bool is_changed   = false;
        uint max_prev_pos = (uint) sqrt(pos);

        for (size_t prev_pos = 1; prev_pos_i <= max_prev_pos; prev_pos_i++) {
            
            if (positions[pos - prev_pos_i] == false) {
                positions[pos] = true;
                is_changed     = true;
            }
        }

        if (is_changed == false)
            positions[pos] = false;
    }


    positions[N] == true ? std::cout << "First" : std::cout << "Second";
    delete [] positions;

    //return;
}




int main() {
    
    uint N = 0;
    std::cin >> N;
    
    winner(N);


    return 0;
}

