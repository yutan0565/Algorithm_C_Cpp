#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_NODE 502
#define ll long long
#define INF 987654321
using namespace std;


vector<vector<int>> graph[MAX_NODE];

int n,m,a,b,c;

bool bellman(int start, vector<ll> &visited)
{   
    visited[start] = 0;
    // node의 개수만큼 반복 해야함
    for (int k = 1; k < n+1; k++)
    {
        for(int i=1 ; i < n+1 ; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {   

                int nx = graph[i][j][0];
                int dis = graph[i][j][1];
                if(visited[i] != INF)
                {
                    if( visited[i] + dis < visited[nx])
                    {
                        if(k == n) return false;
                        visited[nx] =  visited[i] + dis;
                    }
                }   
            }
        }
    }
    return true;
}

int main()
{   
    scanf("%d %d", &n,&m);
    vector<ll> visited(MAX_NODE, INF);
    for(int i=0 ; i < m ; i++)
    {
        scanf("%d %d %d", &a,&b,&c);
        graph[a].push_back({b,c});
    }
    int start =1;
    // cycle이 없는 경우
    if(bellman(start, visited))
    {   
        for(int i = 2 ; i < n+1 ; i++) 
        {   
            if(visited[i] >= INF) printf("%d\n", -1);
            else printf("%d\n", visited[i]);
        }
    }    
    else 
    {
        printf("%d\n", -1);
    }

    return 0;
}