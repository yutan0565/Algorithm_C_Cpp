#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_SIZE 26
using namespace std;

vector<vector<int>> graph(MAX_SIZE, vector<int>(MAX_SIZE));
vector<vector<int>> visited(MAX_SIZE, vector<int>(MAX_SIZE, -1));
vector<int> result;
int n;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int x, int y)
{
    int count = 0;
    queue<vector<int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        q.pop();
        count += 1;
        for(int i=0 ; i < 4 ; i++)
        {
            int nx = a + dx[i]; int ny = b + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n)
            {
                if(visited[nx][ny] == -1)
                {
                    if(graph[nx][ny] == 1)
                    {
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    return count;
}

void print_v(vector<vector<int>> v_2d)
{
    cout << "vector 2d"<< endl;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cout << v_2d[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{   
    scanf("%d", &n);
    for(int i=0 ; i < n ; i++)
    {
        char temp[n]; scanf("%s", &temp);
        for(int j=0 ; j < n ; j++)
        {
            graph[i][j] = temp[j] - '0';
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            if(visited[i][j] == -1 && graph[i][j] == 1)
            {
                int temp = bfs(i,j);
                result.push_back(temp);
            }
        }
    }

    // print_v(graph);
    // print_v(visited);

    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int i=0 ; i < result.size() ; i++) printf("%d\n", result[i]);

    return 0;
}