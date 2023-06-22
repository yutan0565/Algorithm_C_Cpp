#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_NODE 100001
using namespace std;

int n,m,start;
vector<int> visited(MAX_NODE, -1);
vector<int> graph[MAX_NODE];
vector<int> result (MAX_NODE, 0);
int cnt = 1;

void dfs(int x)
{
    if(visited[x] != -1) return;

    visited[x] = 1;
    result[x] = cnt++;

    for(int i=0 ; i < graph[x].size() ; i++)
    {
        int nx = graph[x][i];
        dfs(nx);
    }
}

bool cmp(int i, int j)
{
    return i > j;
}

int main()
{
    scanf("%d %d %d", &n, &m , &start);
    for(int i=0 ; i < m ; i++)
    {
        int u,v; scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0 ; i < n+1 ; i++) sort(graph[i].begin(), graph[i].end(), cmp);
    dfs(start);

    for(int i=1 ; i < n+1 ; i++) printf("%d\n", result[i]);
    return 0;
}