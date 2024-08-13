#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10000000

int arr[MAX_SIZE];
int N, C;

int Install(int distance) {
    int count = 1;
    int lastInstallPosition = arr[0];

    for(int i=1; i<N; i++) {
        if(arr[i] - lastInstallPosition >= distance) {
            count++;
            lastInstallPosition = arr[i];
        }
    }
    return count;
}


int main() {
    scanf("%d %d", &N, &C);
    int X;
    for(int i = 0; i<N; i++) {
        scanf("%d", &X);
        arr[i] = X;
    }

    sort(arr, arr+N);

    int L=1;
    int R=arr[N-1]-arr[0];
    int A=0;
    while(L<=R) {
        int M =(L+R)/2;
        if(Install(M)>=C) {
            A=M;
            L=M+1;
        }
        else {
            R=M-1;
        }
    }
    printf("%d", A);

}