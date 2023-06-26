#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX_N 1001
#define MAX_M 1001

using namespace std;

bool isFull();
int bfs();
void print(vector<vector<int>> g);

int m,n;
vector<vector<int>> visited(MAX_N, vector<int>(MAX_M,-1));
vector<vector<int>> graph(MAX_N, vector<int>(MAX_M));
vector<pair<int,int>> start_v;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isFull()
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j< m ; j++)
        {
            if(graph[i][j] == 0 && visited[i][j] == -1) return false;
        }
    }
    return true;
}

int bfs()
{
    if(isFull()) return 0;
    deque<pair<int,int>> q;
    for(int i = 0 ; i < start_v.size() ; i++)
    {
        q.push_back(make_pair(start_v[i].first, start_v[i].second));
        visited[start_v[i].first][start_v[i].second] = 0;
    }

    int result = 0;

    while(!q.empty())
    {    
        int q_size = q.size();
        for(int qq = 0 ; qq < q_size ; qq++)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop_front();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if(0<=nx && nx<n && 0<=ny && ny<m)
                {
                    if(visited[nx][ny] == -1)
                    {
                        if(graph[nx][ny] != -1)
                        {
                            q.push_back(make_pair(nx,ny));
                            visited[nx][ny] = visited[a][b] + 1;
                            // result = max(result, visited[nx][ny]);
                        }
                    }
                }
            }
        }
        result += 1;
    }
    return result -1;
}

void print(vector<vector<int>> g)
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j< m ; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j< m ; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 1)
            {
                start_v.push_back(make_pair(i,j));
            }
        }
    }
    int result = bfs();
    if(isFull()) printf("%d\n", result);
    else printf("%d\n", -1);

    return 0;
}

/*
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
1 2
2 2
3 2
4 4
5 5
6 3
7 2
8 1
8
*/