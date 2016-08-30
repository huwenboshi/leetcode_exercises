#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    int upbnd = (int)sqrt((float)n);
    int i;
    for(i=2; i<=upbnd; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int countPrimes(int n) {
    int cnt = 0;
    int i;
    for(i=2; i<=n; i++) {
        if(is_prime(i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    printf("%d\n", countPrimes(1500000));
}
