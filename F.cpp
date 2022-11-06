#include <iostream>
#include <cstdlib>


int detect_result(int* table, size_t i, size_t j, uint x, uint y, int shift) {

    int handled = 0;
    for (size_t i_index = i + 1; i_index < x; i_index++)
        handled = (handled + (1 - table[j + i_index * y])) >= 1 ? 1 : 0;
    for (size_t j_index = j + 1; j_index < y; j_index++)
        handled = (handled + (1 - table[j_index + shift])) >= 1 ? 1 : 0;
    size_t i_index = i + 1, j_index = j + 1;
    while (i_index < x && j_index < y) {
        handled = (handled + (1 - table[j_index + i_index * y])) >= 1 ? 1 : 0;
        ++i_index;
        ++j_index;
    }

    return handled;

}


void table_iter(uint x, uint y) {

    int* table = new int[x * y]();
    
    for (int i = x - 1; i >= 0; i--) {
        int shift = i * y;
        for (int j = y - 1; j >= 0; j--) {
            table[shift + j] = detect_result(table, i, j, x, y, shift);
        }

    }

    if (table[0] == 0)
        std::cout << "S";
    if (table[0] == 1)
        std::cout << "F";
    delete [] table;
}





int main() {

    uint a = 0; 
    uint b = 0; 
    std::cin >> a;
    std::cin >> b;

    table_iter(a,b);
    
    return 0;
} 

