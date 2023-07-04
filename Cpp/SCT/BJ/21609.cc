#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>


#define endl '\n'
using namespace std;

#define MAX_N 21
#define MAX_M 6

int result;
int n,m;
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N,0));
vector<vector<int>> visited(MAX_N, vector<int>(MAX_N));

map<int,vector<vector<int>>> block_pos;
map<int,int> cnt_total;
map<int,int> cnt_rainbow;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void print_graph()
{
    cout << "graph" << endl;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
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
    // -1 ����, 0 ������ ,  ������
}

void visited_mpa_init()
{
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            visited[i][j] = -1;
        }
    }
    block_pos.clear();
    cnt_total.clear();
    cnt_rainbow.clear();
}

void bfs(int x, int y, int num)
{
    queue<vector<int>> q;
    visited[x][y] = 1;
    q.push({x,y});
    int now_color = graph[x][y];

    block_pos[num].push_back({x,y});
    cnt_total[num] = 1;
    cnt_rainbow[num] = 0;

    vector<vector<int>> rainbow_pos;

    while(!q.empty())
    {
        int a = q.front()[0]; int b = q.front()[1];
        q.pop();
        for(int d=0 ; d < 4 ; d++)
        {
            int nx = a + dx[d]; int ny = b + dy[d];
            if(0<=nx && nx < n && 0<=ny && ny < n)
            {
                if(visited[nx][ny] == -1)
                {
                    // ������ ����� �ƴѰ��
                    if(graph[nx][ny] != -1)
                    {
                        // ���� ���� ����
                        if(graph[nx][ny] == now_color )
                        {
                            cnt_total[num] += 1;
                            block_pos[num].push_back({nx,ny});
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                        }
                        // ���� ���� -> visited ó�� �Ѱ� ���߿� Ǯ�����
                        else if(graph[nx][ny] == 0)
                        {
                            cnt_total[num] += 1;
                            cnt_rainbow[num] += 1;
                            block_pos[num].push_back({nx,ny});
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                            rainbow_pos.push_back({nx,ny});
                        }
                    }
                }
            }
        }
    }   

    // ������ �湮�� Ǯ���ֱ�
    for(int i=0 ; i < rainbow_pos.size() ; i++)
    {
        visited[rainbow_pos[i][0]][rainbow_pos[i][1]] = -1;
    }
}

vector<int> find_group_candi()
{
    // x,y ��ǥ ����
    vector<int> group_candi;
    int group_num = 1;
    visited_mpa_init();

    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            if(visited[i][j] == -1)
            {
                if(graph[i][j] >= 1) // ���� / �������� �ƴ�
                {
                    bfs(i,j, group_num);
                    if(cnt_total[group_num] >= 2) 
                    {
                        group_candi.push_back(group_num);
                    }
                    group_num += 1;
                }
            }
        }
    }  
    // �ΰ� �̻��� ���� �׷츸, �Ѱ���
    return group_candi;
}

bool cmp(int x, int y)
{
    if(cnt_total[x] == cnt_total[y] && cnt_rainbow[x] == cnt_rainbow[y] && block_pos[x][0] == block_pos[y][0])
    {
        return block_pos[x][1] > block_pos[y][1];
    }
    else
    {
        if(cnt_total[x] == cnt_total[y] && cnt_rainbow[x] == cnt_rainbow[y])
        {
            return block_pos[x][0] > block_pos[y][0];
        }
        else
        {
            if(cnt_total[x] == cnt_total[y])
            {
                return cnt_rainbow[x] > cnt_rainbow[y];
            }
            else
            {
                return cnt_total[x] > cnt_total[y];
            }
        }
    }
}

void del_block(int num)
{
    result += (cnt_total[num]*cnt_total[num]);
    for(int i=0 ; i < block_pos[num].size() ; i++)
    {
        int x = block_pos[num][i][0]; int y = block_pos[num][i][1];
        graph[x][y] = -9;
    }
}

void gravity_on()
{   
    for(int i= n-1 ; i > -1 ; i--)
    {
        for(int j= n-1 ; j > -1 ; j--)
        {   
            // ������� �ƴϰ� , ���� ���� �ƴѰ��
            if(graph[i][j] >= 0)
            {   
                int now_num = graph[i][j];
                graph[i][j] = -9;
                int x = i; int y = j;
                while(true)
                {
                    int nx = x + 1; int ny = y;
                    // ���� ĭ�� ��ĭ�� �ƴ� or ���� ���� ���
                    if(!(0<=nx && nx < n && 0<=ny && ny < n) || graph[nx][ny] != -9)
                    {
                        graph[x][y] = now_num;
                        break;
                    }
                    x = nx; y = ny;
                }
            }
        }
    }
}

void rotate_left()
{
    vector<vector<int>> new_graph(MAX_N, vector<int>(MAX_N,0));
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            new_graph[n-j-1][i] = graph[i][j];
        }
    }
    graph = new_graph;

}

void simulation()
{
    while(true)
    {
        // ũ�Ⱑ ���� ū ��� �׷� ã��
        vector<int> group_candi = find_group_candi();

        if(group_candi.size() == 0) break;

        // ���� ū�� ã�ƾ���
        sort(group_candi.begin(), group_candi.end(), cmp);

        // ����� ��� ���� (���� ����)
        int now_num = group_candi[0];
        del_block(now_num);
        // �߷� �ۿ�

        gravity_on();


        // �ݽð� �������� ȸ��
        rotate_left();

        // �߷� �ۿ� 
        gravity_on();

    }

}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input_init();
    simulation();

    cout << result << endl;

    return 0;
}
