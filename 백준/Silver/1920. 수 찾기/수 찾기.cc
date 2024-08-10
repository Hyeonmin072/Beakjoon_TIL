#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX_SIZE 100000

int arr[MAX_SIZE];
int main() {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+N);

    int M;
    scanf("%d", &M);

    for(int i=0; i<M; i++) {

        int L=0;
        int R=N-1;
        int Mid=(L+R)/2;
        int input;

        scanf("%d", &input);

        while(1) {
            if(L>R){
                printf("0\n");
                break;
            }
            if(arr[Mid] == input) {
                printf("1\n");
                break;
            }
            if(input > arr[Mid]) {
                L=Mid+1;
                Mid = (L+R)/2;
            }
            else if (input < arr[Mid]) {
                R=Mid-1;
                Mid = (L+R)/2;
            }
        }
    }
}



