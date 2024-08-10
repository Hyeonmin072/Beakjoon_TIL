#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 100000

int arr[MAX_SIZE];

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int time;
    int sum = -1;
    for(int number=1; number<=N; number++) {
        scanf("%d", &time);
        arr[number] = sum+time;
        sum += time;
    }


    int input;
    for(int i = 1; i<=Q; i++) {
        scanf("%d", &input);
        int L = 1;
        int R = N;
        while(L<=R) {
            int M = (L+R)/2;
            if(input<=arr[M]){R=M-1;}
            else{L=M+1;}
        }
    printf("%d\n", L);
    }
}



