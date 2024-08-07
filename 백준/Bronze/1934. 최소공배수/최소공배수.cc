#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

int input;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(void) {
    int a,b;

    scanf("%d", &input);

    for(int i = 0; i<input; i++) {
        scanf("%d %d",&a,&b);
        printf("%d\n", a*b / gcd(a,b));
    }
}