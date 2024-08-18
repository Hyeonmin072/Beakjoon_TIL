#define MAX_SIZE 5000
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int people;
int number;
int q[MAX_SIZE*MAX_SIZE];


int main() {
    scanf("%d %d", &people, &number);
    for(int i=1; i<=people; i++) {
        q[i]=i;
    }

int oput =0;
int iput =people;

    printf("<");
    while(iput-1!=oput){
        if(++oput%number==0) {
            printf("%d, ", q[oput]);
        }
        else {
            q[++iput] = q[oput];
        }
    }
    printf("%d", q[++oput]);
    printf(">");
}