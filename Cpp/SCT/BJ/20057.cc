#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define endl '\n'
#define ll long long
#define MAX_LEN 501

using namespace std;

vector<vector<int>> graph(MAX_LEN, vector<int>(MAX_LEN,0));
vector<vector<int>> mask_0(5, vector<int>(5,0));
vector<vector<int>> mask_1(5, vector<int>(5,0));
vector<vector<int>> mask_2(5, vector<int>(5,0));
vector<vector<int>> mask_3(5, vector<int>(5,0));

vector<vector<vector<int>>> mask_v;

vector<int> move_v;

int brush_x; int brush_y;
int center_x; int center_y;
int n;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int out_dust = 0;

vector<vector<int>> rotate_left(vector<vector<int>> mask)
{
    vector<vector<int>> new_mask(5, vector<int>(5,0));
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j=0 ; j < 5 ; j++)
        {
            new_mask[5-j-1][i] = mask[i][j];
        }
    }
    return new_mask;
}

void mask_init()
{
    vector<vector<int>> ori_mask = {{0,0,2,0,0},
                                        {0,10,7,1,0},
                                        {5,-1,0,0,0},
                                        {0,10,7,1,0},
                                        {0,0,2,0,0}
                                        };
    
    mask_0 = ori_mask;
    mask_v.push_back(mask_0);
    mask_1 = rotate_left(mask_0);
    mask_v.push_back(mask_1);
    mask_2 = rotate_left(mask_1);
    mask_v.push_back(mask_2);
    mask_3 = rotate_left(mask_2);
    mask_v.push_back(mask_3);
}

void input_init()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            int temp; cin >> temp;
            graph[i][j] = temp;
        }
    }
    brush_x = n/2; brush_y = n/2;
}

void make_move_v()
{
    // 0 1 2 2 3 3 0 0
    int max_move = n*n -1;
    int direct = 0;
    int cnt = 1;
    int value_cnt = 0;
    while(true)
    {
        for(int i=0 ; i < 2 ; i++)
        {
            for(int j=0 ; j < cnt ; j++)
            {
                move_v.push_back(direct);
                value_cnt += 1;
                if(value_cnt == max_move) return ;
            }
            direct += 1;
            if(direct == 4) direct = 0;
        }
        cnt += 1;
    }
}

void simulation()
{
    // 빗자루 움직이기 시작
    for(int i=0 ; i < move_v.size() ; i++)
    {
        int now_direct = move_v[i];
        // 빗자루 위치 이동
        brush_x = brush_x + dx[now_direct];
        brush_y = brush_y + dy[now_direct];

        // 마스크 계산
        vector<vector<int>> now_mask = mask_v[now_direct];
        vector<vector<int>> now_dust_mask(5, vector<int>(5,0));
        int now_dust = graph[brush_x][brush_y];
        int use_dust = 0;
        int alpha_x, alpha_y;
        // 먼지 없으면 그냥 지나가기
        if(now_dust == 0) continue;

        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j=0 ; j < 5 ; j++)
            {   

                if(now_mask[i][j] == -1)
                {
                    alpha_x = i; alpha_y = j;
                    continue;
                }
                if(now_mask[i][j] == 0) continue;
                int temp = now_dust * now_mask[i][j] / 100;
                now_dust_mask[i][j] = temp;
                use_dust += temp;
            }
        }
        now_dust_mask[alpha_x][alpha_y] = now_dust - use_dust;

        // graph 업데이트 -> 나가는거 측정
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j=0 ; j < 5 ; j++)
            {  
                int nx = brush_x - 2 + i;
                int ny = brush_y -2 + j;
                // 범위 안에 있는 경우
                if(0<=nx && nx <n && 0<=ny && ny<n)
                {
                    graph[nx][ny] += now_dust_mask[i][j];;
                }
                else
                {
                    out_dust += now_dust_mask[i][j];
                }
            }
        }
    }
}

int main()
{
    mask_init();
    input_init();
    make_move_v();
    simulation();

    cout << out_dust << endl;
    return 0;
}