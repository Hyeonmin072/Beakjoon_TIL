// #define MAXN 100
// #include<stdio.h>
// #include<queue>
// #include<algorithm>
// using namespace std;

// int N,M,K,cnt,map[MAXN][MAXN],chk[4][MAXN][MAXN],sx,sy,sd,ex,ey,ed;
// int turn[4][2]={2,3,2,3,0,1,0,1};
// int zx[4]={0,0,1,-1},zy[4]={1,-1,0,0};
// struct temp
// {
// 	int x,y,d;
// }t;
// queue<temp> q;

// void BFS(int x,int y,int d)
// {
// 	int i,nx,ny,nd,tx,ty;

// 	chk[d][x][y]=1;
// 	t.x=x; t.y=y; t.d=d;
// 	q.push(t);
// 	while(!q.empty())
// 	{
// 		t=q.front();
// 		q.pop();
// 		nx=t.x; ny=t.y; nd=t.d;
// 		if(ex-1==nx && ey-1==ny && ed-1==nd)
// 		{
// 			printf("%d",chk[ed-1][ex-1][ey-1]-1);
// 			exit(0);
// 		}
// 		for(i=0;i<2;i++)                 // 회전하는 경우
// 		{
// 			if(!chk[turn[nd][i]][nx][ny])
// 			{
// 				chk[turn[nd][i]][nx][ny]=chk[nd][nx][ny]+1;
// 				t.x=nx; t.y=ny; t.d=turn[nd][i];
// 				q.push(t);
// 			}
// 		}
// 		for(i=1;i<=3;i++)                 // 전진하는 경우
// 		{
// 			tx=nx+zx[nd]*i; ty=ny+zy[nd]*i;
// 			if(tx<0 || tx>=N || ty<0 || ty>=M) break;
// 			if(map[tx][ty]) break;
// 			if(!chk[nd][tx][ty])
// 			{
// 				chk[nd][tx][ty]=chk[nd][nx][ny]+1;
// 				t.x=tx; t.y=ty; t.d=nd;
// 				q.push(t);
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int i,j;

// 	scanf("%d%d",&N,&M); // 행,열
// 	for(i=0;i<N;i++)
// 	{
// 		for(j=0;j<M;j++)
// 		{
// 			scanf("%d",&map[i][j]);
// 		}
// 	}
// 	scanf("%d%d%d",&sx,&sy,&sd);
// 	scanf("%d%d%d",&ex,&ey,&ed);

// 	BFS(sx-1,sy-1,sd-1);
// 	return 0;
// }

#include <iostream>
#include <queue>
using namespace std;

struct Robot {
    int x, y, dir, count;
};

int n, m;
int map[101][101];
int visited[101][101][4]; // (x, y) 좌표에 대해 4개의 방향으로 방문 체크
int dx[] = {0, 0, 1, -1}; // 동, 서, 남, 북
int dy[] = {1, -1, 0, 0}; // 동, 서, 남, 북

// 방향에 따라 동작하는 함수
int getLeftDir(int dir) {
    if (dir == 0) return 3; // 동 -> 북
    if (dir == 1) return 2; // 서 -> 남
    if (dir == 2) return 0; // 남 -> 동
    return 1; // 북 -> 서
}

int getRightDir(int dir) {
    if (dir == 0) return 2; // 동 -> 남
    if (dir == 1) return 3; // 서 -> 북
    if (dir == 2) return 1; // 남 -> 서
    return 0; // 북 -> 동
}

int BFS(int sx, int sy, int sd, int ex, int ey, int ed) {
    queue<Robot> q;
    q.push({sx, sy, sd, 0});
    visited[sx][sy][sd] = 1;

    while (!q.empty()) {
        Robot cur = q.front();
        q.pop();

        // 목표 위치에 도달했을 때
        if (cur.x == ex && cur.y == ey && cur.dir == ed) {
            return cur.count;
        }

        // 1~3칸 전진
        for (int i = 1; i <= 3; ++i) {
            int nx = cur.x + dx[cur.dir] * i;
            int ny = cur.y + dy[cur.dir] * i;

            if (nx <= 0 || nx > n || ny <= 0 || ny > m || map[nx][ny] == 1) break;
            if (!visited[nx][ny][cur.dir]) {
                visited[nx][ny][cur.dir] = 1;
                q.push({nx, ny, cur.dir, cur.count + 1});
            }
        }

        // 왼쪽 회전
        int leftDir = getLeftDir(cur.dir);
        if (!visited[cur.x][cur.y][leftDir]) {
            visited[cur.x][cur.y][leftDir] = 1;
            q.push({cur.x, cur.y, leftDir, cur.count + 1});
        }

        // 오른쪽 회전
        int rightDir = getRightDir(cur.dir);
        if (!visited[cur.x][cur.y][rightDir]) {
            visited[cur.x][cur.y][rightDir] = 1;
            q.push({cur.x, cur.y, rightDir, cur.count + 1});
        }
    }

    return -1; // 도달할 수 없는 경우
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }

    int sx, sy, sd, ex, ey, ed;
    cin >> sx >> sy >> sd >> ex >> ey >> ed;

    // 방향 인덱스 조정 (1 -> 동, 2 -> 서, 3 -> 남, 4 -> 북)
    sd -= 1; 
    ed -= 1; 

    int result = BFS(sx, sy, sd, ex, ey, ed);
    cout << result << endl;

    return 0;
}
