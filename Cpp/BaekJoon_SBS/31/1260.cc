#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

#define MAX_NODE 1001
using namespace std;

vector<int> graph[MAX_NODE];
vector<int> visited_dfs(MAX_NODE, -1);
vector<int> visited_bfs(MAX_NODE, -1);
int n,m,start;

void dfs(int x)
{
    printf("%d ", x);
    visited_dfs[x] = 1;
    for(int i=0 ; i < graph[x].size() ; i++)
    {
        int nx = graph[x][i];
        if(visited_dfs[nx] == -1)
        {
            dfs(nx);
        }
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited_bfs[x] = 1;

    while(!q.empty())
    {
        int a = q.front();
        printf("%d ", a);
        q.pop();
        for(int i = 0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i];
            if(visited_bfs[nx] == -1)
            {
                visited_bfs[nx] = 1;
                q.push(nx);
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
    scanf("%d %d %d", &n,&m,&start);
    for(int i=0 ; i<m ; i++)
    {
        int a,b; scanf("%d %d", &a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0 ; i < n+1 ; i++) sort(graph[i].begin(), graph[i].end(),cmp);

    dfs(start);
    printf("\n");
    bfs(start);

    return 0;
}