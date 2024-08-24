#define MAX_SIZE 101
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;


//나쁜 수열일 경우 return

int num[] = {0, 1, 2, 3};
int list[81];
int leng = 0;
int c;

//좋은 수열 체크
bool chk(int idx) {
    for (int i = 1; i <= (idx + 1) / 2; i++) { //끝에서부터 절반만 확인
        int same = 1; //동일 여부 판단 변수
        for (int j = idx; j > idx - i; j--) { //리스트 끝에서 부터 체크할 반복문
            if (list[j] != list[j - i]) { //현재 위치로 부터 -123 떨어진 위치의 숫자 비교
                same = 0; //같지 않으면 same을 0으로 처리 후
                break; //반복 종료
            }
        }
        if (same) return false; //만약 same이 1이라면 false 리턴
    }
    return true; //same이 0 이라면 true 리턴
}


void back(int n) {
    if (c == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        exit(0);
    }

    for (int i = 1; i <= 3; i++) {
        list[n] = i;
        if (chk(n))
            back(n + 1);
        else
            continue;
    }
}
int main() {
    scanf("%d", &c);
    back(0);
}
