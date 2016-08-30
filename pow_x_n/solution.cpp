#include <stdio.h>

double myPow(double x, int n) {
    if(n == 0)
        return 1.0;
    if(n == 1)
        return x;
    long long int m = n>0 ? n : -n;
    double ans = x;
    long long int cur = 1.0;
    while(cur * 2 < m) {
        cur *= 2;
        ans *= ans;
    }
    ans *= myPow(x, (int)(m-cur));
    return n>0 ? ans : 1.0/ans;
}

int main() {
    double val = myPow(1,2147483647);
    printf("%f\n", val);
}
