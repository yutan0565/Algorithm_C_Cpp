#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>

#define endl '\n'
using namespace std;

#define MAX_N 21
int n;
int graph[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int shark_size = 2;
int now_eat = 0;
int shark_x, shark_y;
int time = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void get_input()
{
    cin >> n;
    for(int i=0 ; i < n ; i ++)
    {
        for(int j=0 ; j < n ; j++)
        {   
            cin >> graph[i][j];
            if(graph[i][j] == 9)
            {
                shark_x = i, shark_y = j;
                graph[i][j] = 0;
            }
        }
    }
}

void reset_visited()
{
    for(int i=0 ; i < n ; i ++)
    {
        for(int j=0 ; j < n ; j++)
        {   
            visited[i][j] = -1;
        }
    }
}

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[0] == v2[0]) return v1[1] < v2[1];
    else return v1[0] < v2[0];
}

int bfs()
{
    reset_visited();
    queue<vector<int>> q;

    int x = shark_x; int y = shark_y;

    q.push({x,y});
    visited[x][y] = 1;
    vector<vector<int>> candi_eat;

    int temp_time = 0;
    while(!q.empty())
    {
        int q_len = q.size();
        for(int qq =0 ; qq < q_len; qq++)
        {   
            int a = q.front()[0]; int b = q.front()[1];
            q.pop();
            for(int i=0 ; i < 4 ; i++)
            {
                int nx = a + dx[i]; 
                int ny = b + dy[i];
                if(0<=nx && nx<n && 0<=ny && ny<n)
                {
                    if(visited[nx][ny] == -1)
                    {
                        // 빈공간 또는 나랑 같은 사이즈
                        if(graph[nx][ny] == 0 || graph[nx][ny] == shark_size)
                        {
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                        }             
                        else if(graph[nx][ny] < shark_size)
                        {
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                            candi_eat.push_back({nx,ny});
                        }
                    }
                }
            }
        }
        temp_time += 1;
        // 만약 먹을 후보군이 존재 한다면
        if(candi_eat.size() != 0)
        {   
            sort(candi_eat.begin(), candi_eat.end(), cmp);
            int eat_x = candi_eat[0][0];
            int eat_y = candi_eat[0][1];
            // 먹은 수 증가 -> 지금 사이즈랑 같으면 크기 키우고 초기화
            now_eat += 1;
            if(now_eat == shark_size)
            {
                shark_size += 1;
                now_eat = 0;
            }
            graph[eat_x][eat_y] = 0;
            shark_x = eat_x; shark_y = eat_y;
            return temp_time;
        }
    }
    return -1;
}


void start_eat_fish()
{
    while(true)
    {
        int eat_time = bfs();
        if(eat_time == -1) break;
        else time += eat_time;
    }
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    // get input info
    get_input();

    // find shark (while can not eat anything)
    start_eat_fish();

    cout << time << endl;

    return 0;
}