#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

#define MAX_N 51
#define MAX_M 101
int n,m;
int result;
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N,0));
vector<vector<int>> cloud_pos;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int dx_cross[] = {1,1,-1,-1};
int dy_cross[] = {1,-1,1,-1};

void input_init()
{   
    // ù ���� ��
    cin >> n >> m;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            int temp; cin >> temp;
            graph[i][j] = temp;
        }
    }

    // ù ���� ��ġ
    cloud_pos.push_back({n-1,0});
    cloud_pos.push_back({n-1,1});
    cloud_pos.push_back({n-2,0});
    cloud_pos.push_back({n-2,1});
}

void move_cloud(int direct, int speed)
{
    vector<vector<int>> new_cloud_pos;
    speed = speed % n;
    for(int i=0 ; i < cloud_pos.size() ; i++)
    {
        int x = cloud_pos[i][0]; 
        int y = cloud_pos[i][1];

        int nx = x + dx[direct]*speed;
        int ny = y + dy[direct]*speed;
        
        if(nx >= 0) nx %= n ;
        else nx += n;
        
        if(ny >= 0) ny %= n ;
        else ny += n;

        // ������ ������ �� ���� �� ����
        graph[nx][ny] += 1;
        new_cloud_pos.push_back({nx,ny});
    }
    cloud_pos = new_cloud_pos;
}

void copy_water()
{
    vector<vector<int>> new_graph(MAX_N, vector<int>(MAX_N,0));

    // �� ����
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            new_graph[i][j] = graph[i][j];
        }
    }

    // �� ���� ����
    for(int i=0 ; i < cloud_pos.size() ; i++)
    {
        int x = cloud_pos[i][0]; 
        int y = cloud_pos[i][1];

        int water_cnt = 0 ;
        for(int d=0 ; d < 4 ; d++)
        {
            int nx = x + dx_cross[d];
            int ny = y + dy_cross[d];
            if(0<=nx && nx < n && 0<=ny && ny < n)
            {   // ���� �ִ� ���
                if(graph[nx][ny] >= 1) water_cnt += 1;
            }
        }
        new_graph[x][y] += water_cnt;
        
    }
    graph = new_graph;
}

void make_cloud()
{
    vector<vector<int>> cloud_graph(MAX_N, vector<int>(MAX_N,0));
    // ���� ��ġ ����
    for(int i=0 ; i < cloud_pos.size() ; i++)
    {
        int x = cloud_pos[i][0]; 
        int y = cloud_pos[i][1];
        cloud_graph[x][y] = 1;
    }

    // ������ ���� ����, ���ο� ���� ����
    vector<vector<int>> new_cloud_pos;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            // ������ ���� ��
            if(cloud_graph[i][j] != 1)
            {
                // ���� 2 �̻� �ΰ�
                if(graph[i][j] >= 2)
                {
                    graph[i][j] -= 2;
                    new_cloud_pos.push_back({i,j});
                }
            }
        }
    }
    cloud_pos = new_cloud_pos;
}

void cal_water()
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            result += graph[i][j];
        }
    }
}

void show_cloud_pos()
{   cout << "show_cloud_pos" << endl;
    for(int i=0 ; i < cloud_pos.size() ; i++)
    {
        int x = cloud_pos[i][0]; 
        int y = cloud_pos[i][1];
        cout << x <<"-"<<y << endl;
    }
}

void show_graph()
{
    cout << "show_grpah" << endl;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void simulation()
{
    for(int i=0 ; i < m ; i++)
    {
        //cout << "============================" << endl;
        // �̵��� ����, �Ÿ�
        int d,s; cin >> d >> s;
        d -= 1;
        // �񱸸� �̵�
        move_cloud(d, s);
        // show_cloud_pos();
        // show_graph();

        // �� ���� ���� ����
        copy_water();
        // show_cloud_pos();
        // show_graph();

        // ���� ����, �� ���̱�
        make_cloud();
        // show_cloud_pos();
        // show_graph();
    }
    
    // ���� �� Ȯ��
    cal_water();

}

int main()
{
    input_init();
    simulation();

    cout << result << endl;
    return 0;
}