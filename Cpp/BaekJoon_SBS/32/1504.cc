#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

#define MAX_NODE 801
using namespace std;

int n,e;
vector<vector<int>> graph[MAX_NODE];
int visited[MAX_NODE];

int bfs(int x, int y)
{
    priority_queue<vector<int>> pq;
    vector<int> visited(MAX_NODE, INT_MAX);
    visited[x] = 0;
    pq.push({0,x});

    while(!pq.empty())
    {
        int now_dis = -pq.top()[0];
        int a = pq.top()[1];
        if(a == y) 
        {
            return visited[a];
        }
        pq.pop();
        for(int i=0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i][0];
            int dis = graph[a][i][1];
            int new_dis = now_dis + dis;
            if(visited[nx] > new_dis)
            {
                visited[nx] = new_dis;
                pq.push({-new_dis, nx});
            }
        }
    }
    return -1;
}

int main()
{   
    scanf("%d %d", &n, &e);
    for(int i=0 ; i < e ; i++)
    {
        int a,b,c; scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int start =1, end = n; 
    int mid_1, mid_2;
    scanf("%d %d", &mid_1, &mid_2);

    int result_1 = 0, result_2 = 0;
    // start -> mid1 -> mid2 -> end
    int dis_1 = bfs(start, mid_1);
    int dis_2 = bfs(mid_1, mid_2);
    int dis_3 = bfs(mid_2, end);
    result_1 = dis_1 + dis_2 + dis_3;
    if(dis_1 == -1 || dis_2 == -1 || dis_3 == -1) result_1 = INT_MAX;

    // √ ±‚»≠
    dis_1 = bfs(start, mid_2);
    dis_2 = bfs(mid_2, mid_1);
    dis_3 = bfs(mid_1, end);
    result_2 = dis_1 + dis_2 + dis_3;
    if(dis_1 == -1 || dis_2 == -1 || dis_3 == -1) result_2 = INT_MAX;

    if(result_1 == INT_MAX && result_2 == INT_MAX) printf("%d\n", -1);
    else printf("%d\n", min(result_1, result_2));
    return 0;
}