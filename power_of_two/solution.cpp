#include <stdio.h>

bool isPowerOfTwo(int n) {
    if(n < 0 || n == 0) {
        return false;
    }
    int num_set_bit = 0;
    for(int i=0; i<32; i++) {
        num_set_bit += (n >> i) & 0x00000001;
        if(num_set_bit > 1) {
            return false;
        }
    }
    return num_set_bit == 1;
}

int main() {
    printf("%d\n", isPowerOfTwo(1));
    printf("%d\n", isPowerOfTwo(5));
}
