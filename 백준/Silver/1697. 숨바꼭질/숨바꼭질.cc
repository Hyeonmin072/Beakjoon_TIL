#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
#define MAX_SIZE 999999

int JohnPoint;
int CowPoint;
int ikey=0;
int okey=0;

int map[MAX_SIZE];
int marker[MAX_SIZE];
bool check[MAX_SIZE];

int main() {
    int count=0;
    scanf("%d %d", &JohnPoint, &CowPoint);
    map[count] += JohnPoint;

    marker[ikey] = 0;

    check[JohnPoint] = true;

    while(true) {

        if(JohnPoint == CowPoint) {
            printf("0");
            break;
        }

        if(map[okey]-1 >= 0 && check[map[okey]-1]==false) {
            map[++ikey] = map[okey]-1;
            check[map[ikey]]=true;
            marker[ikey] = marker[okey]+1;

            if(map[ikey] == CowPoint) {
                printf("%d", marker[ikey]);
                break;
            }
        }



        if(map[okey]+1 <= 100000 && check[map[okey]+1]==false) {
            map[++ikey] = map[okey]+1;
            check[map[ikey]]=true;
            marker[ikey] = marker[okey]+1;

            if(map[ikey] == CowPoint) {
                printf("%d", marker[ikey]);
                break;
            }
        }



        if(map[okey]*2 <= 100000 && check[map[okey]*2]==false) {
            map[++ikey] = map[okey]*2;
            check[map[ikey]]=true;
            marker[ikey] = marker[okey]+1;

            if(map[ikey] == CowPoint) {
                printf("%d", marker[ikey]);
                break;
            }
        }

        okey ++;
    }

}