#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

#define endl '\n'
using namespace std;

#define MAX_NODE 100001 

int n,m,start;
vector<int> visited(MAX_NODE, -1);
vector<int> graph[MAX_NODE];
vector<int> result(MAX_NODE, 0);
int cnt=0;

void dfs(int x)
{
    if(visited[x] != -1) return;
    visited[x] = 1;
    cnt++;
    result[x] = cnt;
    for(int i=0 ; i < graph[x].size() ; i++) dfs(graph[x][i]);
}

int main()
{   
    // cin >> n >> m >> start;
    scanf("%d %d %d", &n,&m,&start);
    for(int i=0 ; i < m ; i++)
    {
        int a,b; 
        scanf("%d %d", &a,&b);
        // cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0 ; i < n+1 ; i++)  sort(graph[i].begin(), graph[i].end());
    dfs(start);
    for(int i=1 ; i < n+1 ; i++) printf("%d\n", result[i]);
    // for(int i=1 ; i < n+1 ; i++) cout << result[i] << endl;
    return 0;
}