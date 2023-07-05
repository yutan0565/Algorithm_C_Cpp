#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define endl '\n'
#define ll long long
#define MAX_LEN 21
#define MAX_SHARK 441

using namespace std;

int n,m,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<vector<int>> graph(MAX_LEN, vector<int>(MAX_LEN,0));
vector<vector<int>> visited(MAX_LEN, vector<int>(MAX_LEN,0));
vector<vector<int>> visit_who(MAX_LEN, vector<int>(MAX_LEN,0));

vector<int> shark_direct(MAX_SHARK);
vector<vector<int>> shark_pos(MAX_SHARK);

vector<vector<vector<int>>> candi_direct(MAX_SHARK, vector<vector<int>>(4, vector<int>(4)));

vector<int> shark_live(MAX_SHARK, 0);

void graph_init()
{
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            int temp; cin >> temp;
            graph[i][j] = temp;
            if(temp != 0) shark_pos[temp] = {i,j};
        }
    }
}

void visited_init()
{
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            visited[i][j] = 0;
        }
    }
}

void direct_init()
{
    for(int i=0 ; i < m ; i++){
        int temp; cin >> temp;
        shark_direct[i+1] = temp -1;
        shark_live[i+1] = 1;
    }
}

void candi_direct_init()
{
    for(int i=0 ; i < m ; i++){
        for(int j=0 ; j < 4 ; j++){
            int a,b,c,d; cin >> a >> b >> c >> d;
            candi_direct[i+1][j] = {a-1,b-1,c-1,d-1};
        }
    }
}

void print_graph()
{
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void spread_smell()
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            if(graph[i][j] != 0)
            {
                visited[i][j] = k;
                visit_who[i][j] = graph[i][j];
            }
        }
    }
}

void down_smell()
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            if(visited[i][j] != 0) visited[i][j] -= 1;
            if(visited[i][j] == 0) visit_who[i][j] = 0;
        }
    }
}

void graph_reset()
{
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            graph[i][j] = 0;
        }
    }
}

int count_live_shark()
{
    int live = 0;
    for(int i=0 ; i < m+1 ; i++)
    {
        live += shark_live[i];
    }
    return live;
}

void move_shark()
{
    graph_reset();
    for(int i=0 ; i < m ; i++)
    {
        int shark_num = i+1;
        if(shark_live[shark_num] == 0) continue;

        int now_x = shark_pos[shark_num][0]; int now_y = shark_pos[shark_num][1];
        int now_direct = shark_direct[shark_num];
        vector<int> now_candi = candi_direct[shark_num][now_direct];


        // 빈공간이 있는지 탐색(아무 냄새도 없는곳 - 우선 순위는 now_candi에 따라서)
        bool empty_flag = false;
        for(int d =0 ; d < 4 ; d++)
        {
            int new_direct = now_candi[d];
            int nx = now_x + dx[new_direct];
            int ny = now_y + dy[new_direct];
            // cout << "new direct : " << new_direct << endl;
            // cout << " now pos : " << now_x << " " << now_y << endl;
            // cout << " new pos : " << nx << " " << ny << endl;
            // 내가 갈수 있는 곳이면
            if(0<=nx && nx<n && 0<=ny && ny<n)
            {   
                if(visited[nx][ny] == 0)
                {   
                    // 냄새는 없는데 상어가 이미 있는 경우 / 죽음
                    if(graph[nx][ny] != 0)
                    {
                        empty_flag = true;
                        shark_live[shark_num] = 0;
                        break;
                    }
                    // 상어가 없는 경우
                    else
                    {
                        empty_flag = true;
                        graph[nx][ny] = shark_num;
                        shark_direct[shark_num] = new_direct;
                        shark_pos[shark_num] = {nx,ny};
                        break;
                    }
                }       
            }
        }

        // 빈공간으로 움직였으면, 다음 상어
        if(empty_flag) continue;

        // 내 냄새가 있는곳 찾아가기
        bool my_flag = false;
        for(int d =0 ; d < 4 ; d++)
        {
            int new_direct = now_candi[d];
            int nx = now_x + dx[new_direct];
            int ny = now_y + dy[new_direct];
            // 내가 갈수 있는 곳이면
            if(0<=nx && nx<n && 0<=ny && ny<n)
            {
                if(visit_who[nx][ny] == shark_num)
                {
                    // 내 냄새가 있는데, 상어가 있음
                    if(graph[nx][ny] != 0)
                    {
                        my_flag = true;
                        shark_live[shark_num] = 0;
                        break;
                    }
                    else
                    {
                        my_flag = true;
                        graph[nx][ny] = shark_num;
                        shark_direct[shark_num] = new_direct;
                        shark_pos[shark_num] = {nx,ny};
                        break;
                    }
                }
            }       
        }
        // 빈공간으로 움직였으면, 다음 상어
        if(my_flag) continue;
        
    }
    // cout << "======================================"<< endl;
    // print_graph();

}


int simulation()
{
    int result = 0;
    while(true)
    {   
        result += 1;
        if(result > 1000) return -1;
        // 자신의 위치에 냄새 뿌림
        spread_smell();

        // 1번 상어부터 움직임 (번호가 낮으면 쫓아냄)
        move_shark();

        // 냄새 감소
        down_smell();

        if(count_live_shark() == 1) break;
        
    }


    return result;
}

int main()
{   
    cin >> n >> m >> k;
    graph_init();
    visited_init();
    direct_init(); 
    candi_direct_init();

    int result = simulation();
    cout << result << endl;
    return 0;
}