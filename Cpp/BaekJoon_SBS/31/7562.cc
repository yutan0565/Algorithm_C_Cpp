#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<vector<int>> visited;
int t, n;
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

int bfs(int s_x, int s_y, int e_x, int e_y)
{
    int result = 0;
    queue<vector<int>> q;
    q.push({s_x, s_y});
    visited[s_x][s_y] = 0;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        q.pop();
        if(a == e_x && b == e_y) return visited[a][b];

        for(int i=0 ; i<8 ; i++)
        {
            int nx = a + dx[i]; int ny = b + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n )
            {
                if(visited[nx][ny] == -1)
                {
                    visited[nx][ny] = visited[a][b] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return result;
}


int main()
{
    scanf("%d", &t);
    for(int t_case = 0 ; t_case < t ; t_case++)
    {    
        scanf("%d", &n);
        graph.assign(n, vector<int>(n,0));
        visited.assign(n, vector<int>(n,-1));
        int s_x, s_y, e_x, e_y; scanf("%d %d %d %d", &s_x, &s_y, &e_x, &e_y);
        int result = bfs(s_x, s_y, e_x, e_y);
        printf("%d\n", result);
    }

    return 0;
}
