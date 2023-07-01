#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

#define MAX_NODE 402
#define INF 10000*402
using namespace std;
vector<vector<int>> graph(MAX_NODE, vector<int>(MAX_NODE,INF));
int v,e;
int a,b,c;

void floyd()
{
    for(int k=1 ; k < v+1 ; k++)
    {
        for(int i=1 ; i < v+1 ; i++)
        {
            for(int j=1 ; j < v+1 ; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j]) 
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &v,&e);
    for(int i=0 ; i < e ; i++)
    {   
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b] = c;
    }

    // floyd-warshall
    floyd();

    int result = INF;
    for(int i=1 ; i < v+1 ; i++)
    {   
        result = min(result, graph[i][i]);  
    }
    if(result == INF) printf("%d\n", -1);
    else printf("%d\n", result);
    return 0;
}