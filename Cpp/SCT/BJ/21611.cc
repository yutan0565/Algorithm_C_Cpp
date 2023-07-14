#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 50
#define MAX_M 101

int n,m;
int result;
int center_x, center_y;
vector<int> result_vector(4,0);
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N,0));
vector<vector<int>> pos_graph(MAX_N, vector<int>(MAX_N,0));
vector<int> move_direct;
vector<int> ball_vector = {0};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dx_make[] = {0,1,0,-1};
int dy_make[] = {-1,0,1,0};

void show_pos_graph()
{
    cout << "show pos graph" << endl;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cout << pos_graph[i][j] << " ";
        }
        cout << endl;
    }
}

void show_ball_vector()
{
    cout << "show_ball_vector" << endl;
    for(int i=0 ; i < ball_vector.size() ; i++)
    {
        cout << ball_vector[i] << " ";
    }
    cout << endl;
}


void input_init()
{
    cin >> n >> m;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            int temp; cin >> temp;
            graph[i][j] = temp;
        }
    }
    center_x = n/2; center_y = n/2;
}

void make_pos_graph_ball_vector()
{
    int direct = 0;
    int cnt = 1;
    int num = 1;

    int x = center_x; int y = center_y;
    while(true)
    {
        for(int i=0 ; i < 2 ; i++)
        {   
            for(int j = 0 ; j < cnt ; j++)
            {
                x = x + dx_make[direct];
                y = y + dy_make[direct];
                pos_graph[x][y] = num;
                num += 1;
                if(num > n*n) return;
                ball_vector.push_back(graph[x][y]);
            }
            direct += 1;
            if(direct >= 4) direct %= 4;
        }
        cnt += 1;
    } 
}

void attack(int direct, int speed)
{
    int x = center_x; int y = center_y;
    for(int i=0 ; i < speed ; i++)
    {
        x = x + dx[direct];
        y = y + dy[direct];
        int ball_index = pos_graph[x][y];
        int ball_num = ball_vector[ball_index];

        if(ball_num == 0) break;
        ball_vector[ball_index] = -1;
    }
}

void dell_ball()
{
    vector<int> new_ball_vector(n*n,0);
    int index = 0;
    for(int i=0 ; i < n*n ; i++)
    {
        if(ball_vector[i] != -1)
        {
            new_ball_vector[index] = ball_vector[i];
            index += 1;
        }
    }
    ball_vector = new_ball_vector;
}

bool find_same_ball()
{
    bool same_flag = false;
    vector<int> temp_vector;
    vector<int> new_ball_vector = {0};

    for(int i=1 ; i < n*n ; i++) 
    {   
        // �������� ���, �׸��α�
        if(ball_vector[i] == 0) break;

        // temp_vector �� �ƹ��͵� ���� ���
        if(temp_vector.size() == 0)
        {
            temp_vector.push_back(ball_vector[i]);
            continue;
        }

        int now_check_ball = temp_vector[0];
        // temp_vector�� ���� ���� ���� ���� ���
        if(now_check_ball == ball_vector[i])
        {
            temp_vector.push_back(ball_vector[i]);
            continue;
        }
        // �ٸ� ���� �� ���
        if(now_check_ball != ball_vector[i])
        {
            // 4�� �̻� ������ ���� �ִ� ��� -- �ƹ��͵� ���� ���� // ������ �ø��� // �ʱ�ȭ
            if(temp_vector.size() >= 4)
            {
                result_vector[temp_vector[0]] += temp_vector.size();
                temp_vector = { ball_vector[i]};
                same_flag = true;
                continue;
            }
            // 4�� �̻��� ���� ��� -- �ٽ� �־��ֱ�
            else
            {
                new_ball_vector.insert(new_ball_vector.end(), temp_vector.begin(), temp_vector.end());
                temp_vector = {ball_vector[i]};
                continue;
            }
        }
    }
    // temp_vector�� ������ �ִ� ���
    if(temp_vector.size() != 0)
    {
        new_ball_vector.insert(new_ball_vector.end(), temp_vector.begin(), temp_vector.end());
    }

    // ��� ���� �ֱ�
    vector<int> temp_ball_vector(n*n,0);
    for(int i=0 ; i < new_ball_vector.size() ; i++) temp_ball_vector[i] = new_ball_vector[i];
    new_ball_vector = temp_ball_vector;
    ball_vector = new_ball_vector;
    
    return same_flag;
}

void spread_ball()
{
    vector<int> temp_vector;
    vector<int> new_ball_vector = {0};

    for(int i=1 ; i < n*n ; i++)
    {
        // �������� ���, �׸��α�
        if(ball_vector[i] == 0) break;

        // �ƹ��͵� ���°��
        if(temp_vector.size() == 0)
        {
            temp_vector.push_back(ball_vector[i]);
            continue;
        }

        int now_check_ball = temp_vector[0];
        // temp_vector�� ���� ���� ���� ���� ���
        if(now_check_ball == ball_vector[i])
        {
            temp_vector.push_back(ball_vector[i]);
            continue;
        }
        // �ٸ� ���� �� ���
        if(now_check_ball != ball_vector[i])
        {
            int ball_cnt = temp_vector.size();
            int ball_num = temp_vector[0];
            vector<int> inser_vector = {ball_cnt, ball_num};
            new_ball_vector.insert(new_ball_vector.end(), inser_vector.begin(), inser_vector.end());
            temp_vector = {ball_vector[i]};
        }
    }

    // ���� ���� �ִ� ���
    if(temp_vector.size() != 0)
    {
        int ball_cnt = temp_vector.size();
        int ball_num = temp_vector[0];
        vector<int> inser_vector = {ball_cnt, ball_num};
        new_ball_vector.insert(new_ball_vector.end(), inser_vector.begin(), inser_vector.end());
    }

    if(new_ball_vector.size() <= n*n)
    {
        vector<int> temp_ball_vector(n*n,0);
        for(int i=0 ; i < new_ball_vector.size() ; i++) temp_ball_vector[i] = new_ball_vector[i];
        new_ball_vector = temp_ball_vector;
    }
    else
    {
        vector<int> temp_ball_vector;
        for(int i=0 ; i < n*n ; i++) temp_ball_vector.push_back(new_ball_vector[i]);
        new_ball_vector = temp_ball_vector;
    }    
    ball_vector = new_ball_vector;


}

void simulation()
{
    for(int i=0 ; i < m ; i++)
    {

        int direct, speed; cin >> direct >> speed;
        direct -= 1;
        // ���ڵ� ����

        attack(direct, speed);

        // �ٽ� ���� -- ������ �� ������ �б�
        dell_ball();
        
        // ������ ������ �����

        while(true)
        {
            bool same_flag = find_same_ball();
            if(same_flag) continue;
            else break;
        }
        // ���� ����
        spread_ball();
    }
}

void cal_result()
{
    for(int i=1 ; i < 4 ; i++)
    {
        result += (i*result_vector[i]);
    }
}

int main()
{
    input_init();
    make_pos_graph_ball_vector();
    simulation();
    cal_result();
    cout << result << endl;
    return 0;
}