#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

int coin[MAX_SIZE]={500,100,50,10,5,1};

int 거스름 (int money) {
    int count =0;
    for(int i = 0; i<6; i++) {
        count += money / coin[i];
        money %= coin[i];
    }
    return count;
}


int main() {
    int input;
    scanf("%d", &input);
    printf("%d",거스름(1000-input));
}