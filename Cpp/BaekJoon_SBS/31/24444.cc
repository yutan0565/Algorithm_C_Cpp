#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_NODE 100001
using namespace std;

int n,m,start;
int cnt = 1;
vector<int> visited(MAX_NODE, -1);
vector<int> graph[MAX_NODE];
vector<int> result(MAX_NODE, 0);

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;

    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        result[a] = cnt++;
        for(int i=0 ; i < graph[a].size();i++)
        {
            int nx = graph[a][i];
            if(visited[nx] == -1)
            {
                q.push(nx);
                visited[nx] = 1;
            }
        }
    }
}


bool cmp(int i, int j)
{
    return i < j;
}

int main()
{   
    scanf("%d %d %d", &n, &m,&start);
    for(int i=0 ; i < m ; i++)
    {
        int u,v; scanf("%d %d", &u , &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0 ; i < n+1 ; i++) sort(graph[i].begin(), graph[i].end(), cmp);

    bfs(start);
    for(int i=1 ; i < n+1 ; i++) printf("%d\n", result[i]);
    return 0;
}