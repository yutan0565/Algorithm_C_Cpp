#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_M 51
#define MAX_N 51

using namespace std;
vector<vector<int>> graph(MAX_N, vector<int>(MAX_M));
vector<vector<int>> visited(MAX_N, vector<int>(MAX_M));
int t,n,m,k;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int x, int y)
{
    queue<vector<int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        q.pop();
        for(int i=0 ; i < 4 ; i++)
        {
            int nx = a + dx[i]; int ny = b + dy[i];
            if(0<=nx&& nx<n && 0<=ny && ny<m)
            {
                if(visited[nx][ny] == -1)
                {
                    if(graph[nx][ny] == 1)
                    {
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

}

void init_vector()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j=0 ; j < m ; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = -1;
        }
    }
}


int main()
{
    scanf("%d", &t);
    for(int t_c=0 ; t_c < t ; t_c++)
    {
        scanf("%d %d %d", &n,&m,&k);
        init_vector();
        for(int i=0 ; i < k ; i++)
        {   
            int a,b; scanf("%d %d", &a, &b);
            graph[a][b] = 1;
        }

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j=0 ; j < m ; j++)
            {   
                if(graph[i][j] == 1 && visited[i][j] == -1)
                {
                    bfs(i,j);
                    cnt += 1;
                }
            }
        }
        printf("%d\n", cnt);
    }
}