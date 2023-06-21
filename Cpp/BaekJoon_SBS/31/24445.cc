#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX_NODE 100001
using namespace std;

int n,m,start;
vector<int> visitied(MAX_NODE, -1);
vector<int> result(MAX_NODE, 0);
vector<int> graph[MAX_NODE];
int cnt = 1;

void bfs(int start)
{
    deque<int> q;
    q.push_back(start);
    visitied[start] = 1;
    
    while(!q.empty())
    {
        int a = q.front();
        q.pop_front();
        result[a] = cnt++;
        for(int i=0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i];
            if(visitied[nx] == -1)
            {
                q.push_back(nx);
                visitied[nx] = 1;
            }
        }
    }
}


bool cmp(int i, int j)
{
    return i > j;
}

int main()
{
    scanf("%d %d %d", &n,&m,&start);
    for(int i=0 ; i < m ; i++)
    {
        int u,v; scanf("%d  %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i < n+1 ; i++) sort(graph[i].begin(), graph[i].end() , cmp);

    bfs(start);

    for(int i = 1; i< n+1 ; i++) printf("%d\n", result[i]);
    return 0;
}