#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100
#
void hanoi(int n, int start, int mid, int end) {
    if(n==1) {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n-1, start, end, mid);
    printf("%d %d\n",start, end);
    hanoi(n-1,mid, start,end);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n,1,2,3);
}
