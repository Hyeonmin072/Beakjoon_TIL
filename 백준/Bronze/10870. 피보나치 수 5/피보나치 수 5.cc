#include <stdio.h>

int fibo(int n) {
    if(n<=1)
        return n;
    return fibo(n-1) + fibo(n-2);
}

int n;
int main(void) {
    scanf("%d", &n);
    printf("%d", fibo(n));
}
