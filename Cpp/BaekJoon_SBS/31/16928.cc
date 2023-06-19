#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;
int n,m;
int graph[101];
int visited[101];

int bfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    
    while(!q.empty())
    {
        int a = q.front(); q.pop();
        if(a == end) return visited[a];
        for(int d = 1 ; d < 7 ; d++)
        {
            int nx = a + d;
            if(0<= nx && nx < 101)
            {
                if(graph[nx] != 0) nx = graph[nx];
                if(visited[nx] > visited[a] + 1)
                {
                    visited[nx] = visited[a] + 1;
                    q.push(nx);
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n , &m);
    for(int i = 0 ; i < 101 ; i++) 
    {   
        graph[i] = 0;
        visited[i] = INT_MAX;
    }
    for(int i=0 ; i < n ; i++)
    {
        int x,y; scanf("%d %d", &x, &y);
        graph[x] = y;
    }

    for(int i=0 ; i < m ; i++)
    {
        int x,y; scanf("%d %d", &x, &y);
        graph[x] = y;
    }
    int start = 1, end = 100;
    int result = bfs(start, end);
    printf("%d\n", result);

    return 0;
}
