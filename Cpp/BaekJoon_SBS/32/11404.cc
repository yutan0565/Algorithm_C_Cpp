#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

#define MAX_NODE 102
using namespace std;
vector<vector<int>> graph[MAX_NODE];
int n,m;
int a,b,c;

void daik(int start, vector<int> &visited)
{
    priority_queue<vector<int>> pq;
    pq.push({0,start});
    visited[start] = 0;

    while(!pq.empty())
    {
        int now_dis = -pq.top()[0]; int a = pq.top()[1];
        pq.pop();
        for(int i=0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i][0]; int dis = graph[a][i][1];
            int new_dis = now_dis + dis;
            if(new_dis < visited[nx])
            {
                visited[nx] = new_dis;
                pq.push({-new_dis, nx});
            }
        }
    }
}

void show_dis(vector<int> visited)
{
    for(int i=1 ; i < n+1 ; i++)
    {   
        if(visited[i] == INT_MAX) printf("%d ", 0);
        else printf("%d ", visited[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%d %d", &n,&m);
    for(int i=0 ; i < m ;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
    }

    for(int i=1 ; i < n+1 ; i++)
    {
        int start = i;
        vector<int> visited(MAX_NODE, INT_MAX);
        daik(start, visited);
        show_dis(visited);
    }
    return 0;
}