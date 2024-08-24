#define MAX_SIZE 101
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int arr[MAX_SIZE];
int ans=0;

bool check(int floor) { //퀸 위치 유효성 체크
    for(int i=0; i<floor; i++) {
        if(arr[i] == arr[floor] || abs(arr[floor]-arr[i])==floor-i)
            //i==floor : 같은 열에 퀸이 존재
            //abs(floor-i) == floor-i // 대각에 있다면
            return false;
    }
    return true;
}

void nqueen(int n) { //퀸 배치
    if(n==N) ans++; //퀸을 N개 배치했을 때 정답 개수 +
    else {
        for(int i=0; i<N; i++) {
            arr[n]=i;
            if(check(n)) //유효성 체크
                nqueen(n+1); //유효하면 다음 층으로
        }
    }
}

int main() {
    scanf("%d", &N);
    nqueen(0);
    printf("%d", ans);
}
