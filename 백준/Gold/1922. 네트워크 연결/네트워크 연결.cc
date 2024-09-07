#define MAX_SIZE 1001
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int a,b,c;
int P;
int L;

bool chk[MAX_SIZE];

int map[MAX_SIZE][MAX_SIZE];
int minCost[MAX_SIZE];
int sum;

const int INF = 10001;

void fn(int n) {
    chk[n]=true;

    //초기값 설정
    for(int i=1; i<=P; i++) {
        if(!chk[i] && map[n][i] < minCost[i]) {
            minCost[i]=map[n][i];
        }
    }
    //다음 연결 노드
    int next=0;
    int min_cost=INF;
    for(int i=1;i<=P; i++) {
        if(!chk[i] && minCost[i] < min_cost) {
            min_cost = minCost[i];
            next=i;
        }
    }
    if(next==0) return;

    sum+=min_cost;
    fn(next);
}

int main() {
    scanf("%d", &P);
    scanf("%d", &L);

    //각 배열 최대값으로 초기화
    for(int i=1; i<=P; i++) {
        minCost[i]=INF;
        for(int j=1; j<=P; j++) {
            map[i][j]=INF;
        }
    }

    //비용 마킹
    for(int i=1; i<=L; i++) {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
        map[b][a] = c;
    }


    fn(1);
    printf("%d", sum);


    // 비용 포지션 체크
    // for(int i=1; i<=P; i++) {
    //     for(int j=1; j<=P; j++) {
    //         printf("%d\t", map[i][j]);
    //     }
    //     printf("\n");
    // }





}

