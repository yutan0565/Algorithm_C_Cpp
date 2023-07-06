#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define endl '\n'
#define ll long long
using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int max_eat = -1;

struct Fish 
{
    int x = 0;      //����� x��ǥ
    int y = 0;      //����� y��ǥ
    int direct = 0;    //����� �̵�����
    int fish_number = 0;    //����� ����
    bool live = true;  
};

void graph_init(vector<vector<int>>& graph, Fish* fish_list)
{

    for(int i=0 ; i < 4 ; i++)
    {
        for(int j=0 ; j < 4 ; j++)
        {
            int a,b; cin >> a >> b;
            a--; b--;
            graph[i][j] = a;
            fish_list[a].x = i;
            fish_list[a].y = j;
            fish_list[a].direct = b;
            fish_list[a].fish_number = a + 1;
            fish_list[a].live = true;
        }
    }
}

void dfs(vector<vector<int>>& graph, Fish* fish_list, int shark_x, int shark_y, int sum)
{
    vector<vector<int>> new_graph(4,vector<int>(4));
    Fish new_fish_list[16];

    // ���� ���� ��� �ϱ�
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++)
        {
            new_graph[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < 16; i++)
    {
        new_fish_list[i] = fish_list[i];
    }

    // ����� ����
    int eat_num = new_graph[shark_x][shark_y];
    new_graph[shark_x][shark_y] = -1;
    // �̵� ���� ����
    int shark_direct = new_fish_list[eat_num].direct;
    new_fish_list[eat_num].live = false;

    // ���� ����
    sum += new_fish_list[eat_num].fish_number;
    max_eat = max(sum, max_eat);

    // ����� �̵�
    for(int i=0 ; i < 16 ; i++)
    {
        if(new_fish_list[i].live)
        {
            int a = new_fish_list[i].x;
            int b = new_fish_list[i].y;
            int now_d = new_fish_list[i].direct;

            // �� �� �ִ� ���� ã���ֱ�
            int nx = a + dx[now_d%8];
            int ny = b + dy[now_d%8];
            while(true)
            {
                if(0<=nx && nx<4 && 0<=ny && ny<4)
                {
                    if(!(nx == shark_x && ny == shark_y))
                    {
                        break;
                    }
                }
                now_d ++;
                nx = a + dx[now_d%8];
                ny = b + dy[now_d%8];
            }
            // ������� ���
            if(new_graph[nx][ny] == -1)
            {
                new_fish_list[i].x = nx;
                new_fish_list[i].y = ny;
                new_fish_list[i].direct = now_d;
                new_graph[a][b] = -1;
                new_graph[nx][ny] = i;
            }
            // ����Ⱑ �ִ� ���
            else
            {
                int swap_fish = new_graph[nx][ny];
                new_fish_list[i].x = nx;
                new_fish_list[i].y = ny;
                new_fish_list[i].direct = now_d;
                new_fish_list[swap_fish].x = a;
                new_fish_list[swap_fish].y = b;

                new_graph[nx][ny] = i;
                new_graph[a][b] = swap_fish;
            }
        }
    }

    // ��� �̵�
    for (int i = 1; i < 4; i++) {
        int plus_x = dx[shark_direct % 8] * i;
        int plus_y = dy[shark_direct % 8] * i;
        int nx = shark_x + plus_x;
        int ny = shark_y + plus_y;

        if(0<=nx && nx<4 && 0<=ny && ny<4)
        {
            if(new_graph[nx][ny] != -1)
            {
                dfs(new_graph, new_fish_list, nx, ny, sum);
            }
        }      
    }
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> graph(4,vector<int>(4));
    Fish fish_list[16];
    graph_init(graph, fish_list);

    dfs(graph, fish_list, 0,0,0);
    cout << max_eat << endl;

    return 0;
}