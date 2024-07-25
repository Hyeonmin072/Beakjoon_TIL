#include <stdio.h>
#include <stdlib.h>
int map[25][25];
void back(int a, int b, int a1, int b1, int i, int j, int cnt)
{
    if(cnt==5 && map[a1+i][b1+j]!=map[a][b]) // 오목이면서 육목이 아닌경우 출력
    {
        printf("%d\n%d %d\n",map[a][b],a,b);
        exit(0);
    }
 
    if(map[a1+i][b1+j]==map[a][b]) back(a,b,a1+i,b1+j,i,j,cnt+1);
}
int main(void)
{
    int i,j;
 
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=19; j++)
            scanf("%d",&map[i][j]);
    }
 
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=19; j++)
        {
            if(map[i][j]==map[i][j+1] && map[i][j]!=map[i][j-1] && map[i][j]!=0)  back(i,j,i,j,0,1,1);        //오른쪽
            if(map[i][j]==map[i+1][j] && map[i][j]!=map[i-1][j] && map[i][j]!=0)  back(i,j,i,j,1,0,1);        //아래쪽
            if(map[i][j]==map[i+1][j+1] && map[i][j]!=map[i-1][j-1] && map[i][j]!=0) back(i,j,i,j,1,1,1);     // 아래대각선
            if(map[i][j]==map[i-1][j+1] && map[i][j]!=map[i+1][j-1] && map[i][j]!=0) back(i,j,i,j,-1,1,1);    // 위 대각선
        }
    }

	printf("0"); // 비긴경우
    return 0;
}