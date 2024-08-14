#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100000

int N; // 옷 개수
int A[MAX_SIZE]; // 물 배열
int K; // 라디에이터 효과

bool Dry(int MiddleTime) {
    long long radiator = 0;
    for(int i = 0; i < N; i++) {
        int water = max(0, A[i] - MiddleTime);
        radiator += (water + K - 1) / K;
    }
    return radiator <= MiddleTime;
}

int main() {
    scanf("%d", &N);
    int top = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        top = max(top, A[i]);
    }
    scanf("%d", &K);
    
    if (K == 1) {
        printf("%d\n", top);
        return 0;
    }
    
    K--;
    
    int L = 0;
    int R = top;
    int result = top;
    while(L <= R) {
        int M = L + (R - L) / 2;
        if(Dry(M)) {
            result = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    printf("%d\n", result);
    return 0;
}