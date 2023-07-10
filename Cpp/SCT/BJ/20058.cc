#include <iostream>
#include <vector>   
#include <algorithm>
#include <queue>
#include <cmath>

#define endl '\n'
#define ll long long
using namespace std;

#define MAX_LEN 129
#define MAX_Q 1000

int n,q;
int total_size;
vector<vector<int>> graph(MAX_LEN, vector<int>(MAX_LEN, 0));
vector<vector<int>> visited(MAX_LEN, vector<int>(MAX_LEN, -1));
vector<int> level_v;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int ice_cnt=0;
int max_group_size=0;


void input_init()
{
    cin >> n >> q;
    total_size = pow(2,n);

    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {
            int temp; cin >> temp;
            graph[i][j] = temp;
        }
    }

    for(int i=0 ; i < q ; i++)
    {
        int temp; cin >> temp;
        level_v.push_back(temp);
    }
}

void print_graph()
{
    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_right(int level)
{
    vector<vector<int>> new_graph(MAX_LEN, vector<int>(MAX_LEN, 0));
    int small_size = pow(2,level);

    for(int x=0 ; x < total_size ; x += small_size)
    {
        for(int y=0 ; y < total_size ; y += small_size)
        {
            // 공간 모양이 유지되는 공간
            for(int i=0 ; i < small_size ; i++)
            {
                for(int j=0 ; j < small_size ; j++)
                {
                    new_graph[x+j][y+small_size - i - 1] = graph[x+i][y+j];
                }
            }
        }
    }
    graph = new_graph;
}

void down_ice()
{
    vector<vector<int>> new_graph(MAX_LEN, vector<int>(MAX_LEN, 0));
    // 기존 그래프 복사
    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {   
            new_graph[i][j] = graph[i][j];
        }
    }

    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {   
            // 얼음있는 공간은 패스
            if(graph[i][j] == 0) continue;

            int ice_cnt = 0 ;
            for(int d=0 ; d < 4 ; d++)
            {
                int nx = i + dx[d]; int ny = j + dy[d];
                if(0<=nx && nx <total_size && 0<=ny && ny <total_size)
                {
                    if(graph[nx][ny] != 0) ice_cnt += 1;
                }
            }

            // 얼음이 2개 이하면은 줄어듬
            if(ice_cnt <= 2) new_graph[i][j] -= 1;
        }
    }
    graph = new_graph;
}

void bfs(int x, int y)
{
    queue<vector<int>> q;
    int group_size = 1;
    q.push({x,y});
    visited[x][y] = 1;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        q.pop();
        for(int d=0 ; d < 4 ; d++)
        {
            int nx = a + dx[d]; int ny = b + dy[d];
            if(0<=nx && nx <total_size && 0<=ny && ny <total_size)
            {
                if(visited[nx][ny] == -1)
                {
                    if(graph[nx][ny] != 0)
                    {
                        group_size += 1;
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    max_group_size = max(group_size, max_group_size);
}

void count_ice()
{
    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {   
            ice_cnt += graph[i][j];

        }
    }
}


void simulation()
{   
    for(int i=0 ; i < q ; i++)
    {
        int now_level = level_v[i];
        // 오른쪽으로 돌리기 -- level 0 이면, 안돌림
        if(now_level != 0) rotate_right(now_level);
        // 얼음 줄이기
        down_ice();
    }

    // 어름 개수 구하기
    count_ice();

    // 그룹 최대 사이즈 구하기 
    for(int i=0 ; i < total_size ; i++)
    {
        for(int j=0 ; j < total_size ; j++)
        {   
            if(visited[i][j] == -1 && graph[i][j] != 0) bfs(i,j);
        }
    }


}


int main()
{
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 입력 받기
    input_init();
    // simulation 시작
    simulation();

    cout << ice_cnt << endl;
    cout << max_group_size << endl;

    return 0;
}