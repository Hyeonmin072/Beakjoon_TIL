#define MAX_SIZE 1001
#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[MAX_SIZE];
int n, c;
int depth[MAX_SIZE];
int bt[MAX_SIZE];
int M = 0;
int result[MAX_SIZE];

void fn() {
    for (int i = 0; i < n; i++) {
        depth[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dp[i] > dp[j] && depth[i] < depth[j] + 1) {
                depth[i] = depth[j] + 1;
                bt[i] = j;
            }
        }
        if (depth[i] > depth[M]) {
            M = i;
        }
    }

    int current = M;
    while (current != -1) {
        result[c++] = dp[current];
        current = bt[current];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dp[i]);
        bt[i] = -1;
    }

    fn();

    printf("%d\n", c);
    for (int i = c - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

