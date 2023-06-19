#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_SIZE 101
using namespace std;
int n,m;
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int bfs(int start[], int end[])
{
    queue<vector<int>> q;
    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        if(end[0] == a && end[1] == b) return visited[a][b];
        q.pop();
        for(int i=0 ; i < 4 ; i++)
        {
            int nx = a + dx[i]; int ny = b + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny < m)
            {
                if(visited[nx][ny] == -1)
                {
                    if(graph[nx][ny] == 1)
                    {
                        visited[nx][ny] = visited[a][b] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    return -1;
}


int main()
{   
    scanf("%d %d", &n,&m);
    for(int i=0 ; i < n ; i++)
    {   
        char str[m]; scanf("%s", str);
        for(int j=0 ; j < m ; j++)
        {
            graph[i][j] = str[j] - '0';
            visited[i][j] = -1;
        }
    }
    int start[2] = {0,0};
    int end[2] = {n-1,m-1};

    int result = bfs(start, end);
    printf("%d\n", result);
    return 0;
}