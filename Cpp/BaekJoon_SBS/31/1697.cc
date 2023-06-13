#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_NODE 100001
using namespace std;
int graph[MAX_NODE];
int visited[MAX_NODE];
int n,k;

int bfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        if(a == end) return visited[a];

        for(int i = 0 ; i < 3 ; i++)
        {   
            int nx;
            if(i == 0) nx = a + 1;
            else if(i == 1) nx = a - 1;
            else if(i == 2 && a != 0) nx = 2*a;
            if(visited[nx] == -1)
            {
                visited[nx] = visited[a] + 1;
                q.push(nx); 
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    if(n >= k)
    {
        printf("%d\n", n-k);
        return 0;
    }
    for(int i=0 ; i < MAX_NODE ; i++) visited[i] = -1;
    int result = bfs(n,k);
    printf("%d\n", result);
    return 0;
}