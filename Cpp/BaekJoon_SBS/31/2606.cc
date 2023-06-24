#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>

#define MAX_NODE 1001
using namespace std;

vector<int> visited(MAX_NODE, -1);
vector<int> graph[MAX_NODE];
int n,m;

int bfs(int x)
{
    deque<int> q;
    q.push_back(x);
    visited[x] = 1;
    int result = 0;

    while(!q.empty())
    {
        int a = q.front();
        q.pop_front();
        for(int i=0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i];
            if(visited[nx] == -1)
            {
                q.push_back(nx);
                visited[nx] = 1;
                result += 1;
            }
        }
    }
    return result;
}

int main()
{
    scanf("%d %d", &n ,&m);
    for(int i=0 ; i < m ; i++)
    {
        int a,b; scanf("%d %d", &a ,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int start = 1;
    int result = bfs(start);
    printf("%d\n", result);

    return 0;
}