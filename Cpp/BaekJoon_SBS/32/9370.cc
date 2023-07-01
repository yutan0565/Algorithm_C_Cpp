#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

#define MAX_NODE 2001
using namespace std;
int T, n, m, t;
int start,g,h;
vector<vector<int>> graph[MAX_NODE];

void daik(int x, vector<int> &visited)
{
    priority_queue<vector<int>> pq;
    pq.push({0, x});    
    visited[x] = 0;

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

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n,&m,&t);
        // 예술가 출발,  교차로 사이 노드;
        scanf("%d %d %d",&start, &g, &h);
        vector<int> candi_v;
        int gap = 0;

        for(int i=0 ; i < n+1 ; i++) graph[i].clear();
        for(int i=0 ; i<m ; i++)
        {
            int a,b,d; scanf("%d %d %d",&a, &b, &d);
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
            if((a == g && b == h) || (a == h && b == g)) gap = d;
        }
        for(int i=0 ; i<t ; i++)
        {
            int a; scanf("%d", &a);
            candi_v.push_back(a);
        }
        
        // 각 점을 지날때의 거리 
        vector<int> visited_total(MAX_NODE, INT_MAX);
        daik(start, visited_total);

        // 두번째로 지난 점 찾기
        int second = 0;
        if(visited_total[g] < visited_total[h]) second = h;
        else second = g;

        vector<int> visited_second(MAX_NODE, INT_MAX);
        daik(second, visited_second);

        // 그냥 측정한 거리랑,  second 점 지난거랑 같아야함
        vector<int> result;
        for(int i=0 ; i < candi_v.size() ; i++)
        {
            int candi_point = candi_v[i];
            if(visited_total[candi_point] == visited_second[candi_point]+ visited_total[second]) result.push_back(candi_point);
        }

        sort(result.begin(), result.end());
        for(int i=0 ; i < result.size() ; i++) printf("%d ", result[i]);
        printf("\n");


    }   
    return 0;
}