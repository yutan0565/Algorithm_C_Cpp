#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX_M 101
#define MAX_N 101
#define MAX_H 101
using namespace std;

int visited[MAX_H][MAX_N][MAX_M];
int graph[MAX_H][MAX_N][MAX_M];
vector<vector<int>> start_v;
int m,n,h;

int dx[6] = {1,-1,0,0,0,0};
int dy[6]  ={0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int bfs()
{
    int result = 0;
    deque<vector<int>> q;
    for(int i=0 ; i < start_v.size() ;i++)
    {
        q.push_back({start_v[i][0],start_v[i][1],start_v[i][2]});
        visited[start_v[i][0]][start_v[i][1]][start_v[i][2]] = 1;
    }

    while(!q.empty())
    {   
        result += 1;
        int q_size = q.size();
        for(int qq=0 ; qq < q_size ; qq++)
        {
            int a = q.front()[0]; int b = q.front()[1]; int c = q.front()[2];  
            q.pop_front();
            for(int i = 0 ; i<6 ;i++)
            {
                int nz = a + dz[i]; int nx = b + dx[i]; int ny = c + dy[i]; 
                if(0<=nz && nz<h && 0<=nx && nx<n && 0<=ny && ny<m)
                {
                    if(visited[nz][nx][ny] == -1)
                    {
                        if(graph[nz][nx][ny] != -1)
                        {
                            q.push_back({nz,nx,ny});
                            visited[nz][nx][ny] = visited[a][b][c] + 1;
                            
                        }   
                    }
                }
            }
        }
    }

    for(int i=0 ; i < h ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            for(int k=0 ; k < m ; k++)
            {   
                if(graph[i][j][k] != -1 && visited[i][j][k] == -1) return -1;
            }
        }
    }
    return result -1;
}

void print()
{
    for(int i=0 ; i < h ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            for(int k=0 ; k < m ; k++)
            {   
                cout << visited[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    scanf("%d %d %d", &m,&n,&h);
    for(int i=0 ; i < h ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            for(int k=0 ; k < m ; k++)
            {   
                scanf("%d", &graph[i][j][k]);
                visited[i][j][k] = -1;
                if(graph[i][j][k] == 1)
                {
                    start_v.push_back({i,j,k});
                }
            }
        }
    }

    int result = bfs();
    printf("%d\n", result);
    return 0;
}
