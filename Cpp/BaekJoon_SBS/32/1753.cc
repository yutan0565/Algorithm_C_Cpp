#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

#define MAX_NODE 20001
#define endl "\n"
using namespace std;

int v,e;
int start;
vector<int> visited(MAX_NODE, INT_MAX);
vector<pair<int,int>> graph[MAX_NODE];

void daik()
{
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    visited[start] = 0;

    while(!pq.empty())
    {
        int dis = -pq.top().first;
        int a = pq.top().second;
        pq.pop();

        if(visited[a] < dis) continue;

        for(int i = 0 ; i < graph[a].size(); i++)
        {
            int nx = graph[a][i].first;
            int new_dis = graph[a][i].second + dis;
            if(visited[nx] > new_dis)
            {
                visited[nx] = new_dis;
                pq.push(make_pair(-new_dis, nx));
            }
        }
    }
}


int main()
{   
    cin >> v >> e;
    cin >> start;
    for(int i=0 ; i < e ; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w)); 
    }

    daik();

    for(int i = 1 ; i < v+1 ; i++)
    {
        if(visited[i] != INT_MAX) cout << visited[i] << endl;
        else cout << "INF" << endl;
    }

    return 0;
}