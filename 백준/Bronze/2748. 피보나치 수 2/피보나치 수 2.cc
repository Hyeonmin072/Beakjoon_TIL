#define MAX_SIZE 101
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

long long memo[MAX_SIZE];
int s;

void fibo(int n) {

    if(n<=2) {
        memo[n]=1;
        return;
    }
    if(memo[n])
        return;

    fibo(n-2);
    fibo(n-1);

    memo[n]=memo[n-2]+memo[n-1];
}

int main() {
    scanf("%d", &s);
    if(!s){printf("0");exit(0);}
    fibo(s);
    printf("%lld", memo[s]);
}
