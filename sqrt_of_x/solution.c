#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x) {
    int ans = 0, low=0, high=x/2+1;
    while(low<=high) {
        ans = (high-low)/2+low;
        if(ans != 0 && ((ans*ans)/ans != ans || ans*ans > x))
            high = ans-1;
        else if(ans*ans == x)
            return ans;
        else
            low = ans+1;
    }
    if(ans*ans > x)
        return ans-1;
    return ans;
}

int main() {
    printf("%d\n", mySqrt(0));
    printf("%d\n", mySqrt(16));
    printf("%d\n", mySqrt(2147395599));
    printf("%d\n", mySqrt(8192));
}
