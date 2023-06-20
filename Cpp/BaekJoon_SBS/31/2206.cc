#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_SIZE 1001
using namespace std;
vector<vector<int>> graph;
vector<vector<vector<int>>> visited;
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int s_x, int s_y, int e_x, int e_y)
{   
    queue<vector<int>> q;
    q.push({s_x,s_y,0});
    visited[s_x][s_y][0] = 1;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1]; int flag = q.front()[2];
        q.pop();
        if(a == e_x && b == e_y) return visited[a][b][flag];

        for(int i=0 ; i < 4 ; i++)
        {
            int nx = a + dx[i]; int ny = b + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m)
            {   
                // 벽이 있는 경우
                if(graph[nx][ny] == 1)
                {   
                    // 아직 부수지 않은 경우
                    if(flag == 0)
                    {
                        if(visited[nx][ny][1] == -1)
                        {
                            visited[nx][ny][1] = visited[a][b][0] + 1;
                            q.push({nx,ny,1}) ;
                        }
                    }
                }
                else if(graph[nx][ny] == 0)
                {
                    if(visited[nx][ny][flag] == -1)
                    {
                        visited[nx][ny][flag] = visited[a][b][flag] + 1;
                        q.push({nx,ny,flag});
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{   
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<vector<int>>(m, vector<int>(2,-1)));
    for(int i=0 ; i < n ; i++)
    {
        char temp[m]; scanf("%s", temp);
        for(int j=0 ; j< m ; j++)
        {
            graph[i][j] = temp[j] - '0';
        }
    }
    int s_x=0, s_y=0, e_x=n-1, e_y=m-1;
    int result = bfs(s_x, s_y, e_x, e_y);
    printf("%d\n", result);
    return 0;
}