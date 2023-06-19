#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_NODE 20001
using namespace std;
int k, v, e;
vector<int> graph[MAX_NODE];
int visited[MAX_NODE];

void init(int num_node)
{
    for(int i=0 ; i < num_node+1 ; i++)
    {
        graph[i].clear();
        visited[i] = 0;
    }
}

void make_graph(int v, int e)
{
    for(int i=0 ; i < e ; i++)
    {
        int a,b; scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = -1;

    while(!q.empty())
    {
        int a = q.front(); int type = visited[a];
        q.pop();
        for(int i=0 ; i < graph[a].size() ; i++)
        {
            int nx = graph[a][i]; 
            int next_type = -type;
            if(visited[nx] == 0)
            {
                visited[nx] = next_type;
                q.push(nx);
            }
        }
    }
}

bool isBinGraph()
{
    for(int i=1 ; i < v+1 ; i++)
    {
        int now_type = visited[i];
        for(int j =0 ; j < graph[i].size() ; j++)
        {
            int nx = graph[i][j];
            int nx_type = visited[nx];
            if(now_type == nx_type) return false;
        }
    }
    return true;
}

int main()
{   
    scanf("%d", &k);
    while(k--)
    {   
        scanf("%d %d", &v, &e);
        // 초기화
        init(v);
        // 그래프 만들기
        make_graph(v,e);
        // 각 노드 기준 bfs 진행
        for(int i=1 ; i < v+1 ; i++)
        {
            if(visited[i] == 0) bfs(i);
        }
        
        if(isBinGraph()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}