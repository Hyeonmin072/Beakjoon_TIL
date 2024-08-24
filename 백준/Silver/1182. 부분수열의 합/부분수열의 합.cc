#define MAX_SIZE 101
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int list[MAX_SIZE];
int N, S;
int c=0;

void fuc(int n, int sum) {
    if(n==N) {
        if(sum == S)
            c++;
        return;
    }

    fuc(n + 1, sum + list[n]);
    fuc(n + 1, sum);

}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }

    fuc(0, 0);
    if(S==0)c--;
    printf("%d\n",c);
}
