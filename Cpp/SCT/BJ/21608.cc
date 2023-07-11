#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define endl '\n'
#define ll long long
using namespace std;

#define MAX_LEN 21
#define MAX_NUM 441

int n;
int num_stu;
int score;

vector<vector<int>> graph(MAX_LEN, vector<int>(MAX_LEN,0));
map<int, vector<int>> friend_map;
vector<int> order_v;
vector<int> score_v = {0,1,10,100,1000};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void input_init()
{
    cin >> n;
    num_stu = n*n;
    for(int i=0 ; i < num_stu ; i++)
    {
        int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
        friend_map[a] = {b,c,d,e};
        order_v.push_back(a);
    }
}

void move_stu(int num)
{
    vector<int> friends_v = friend_map[num];
    int max_friend = -1;
    int max_empty = -1;

    int x = 0 ; int y = 0 ;

    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            // 사람이 이미 있는곳이면 패스
            if(graph[i][j] != 0) continue;
            int now_friend = 0;
            int now_empty = 0;
            for(int d = 0 ; d < 4 ; d++)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(0<=nx && nx<n && 0<=ny && ny<n)
                {
                    // 빈공간인 경우
                    if(graph[nx][ny] == 0) now_empty += 1;
                    // 친구가 존재함
                    else if(find(friends_v.begin(), friends_v.end(), graph[nx][ny]) != friends_v.end()) now_friend += 1;
                }    
            }

            if(now_friend > max_friend)
            {
                x = i; y = j;
                max_friend = now_friend;
                max_empty = now_empty;
            }
            else if(now_friend == max_friend)
            {        
                if(now_empty > max_empty)
                {
                    x = i; y = j;
                    max_friend = now_friend;
                    max_empty = now_empty;
                }
            }
        }
    }
    graph[x][y] = num;
}

void print_graph()
{
    cout << "=============================" << endl;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void cal_score()
{
    score = 0;
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            // 사람이 이미 있는곳이면 패스
            vector<int> friends_v = friend_map[graph[i][j]];

            int now_friend = 0;
            for(int d = 0 ; d < 4 ; d++)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(0<=nx && nx<n && 0<=ny && ny<n)
                {
                    if(find(friends_v.begin(), friends_v.end(), graph[nx][ny]) != friends_v.end()) now_friend += 1;
                }
            }
            score += score_v[now_friend];
        }
    }
}


void simulation()
{
    for(int i= 0 ; i < num_stu ; i++)
    {
        int now_num = order_v[i];
        move_stu(now_num);
    }

    // 점수 계산하기
    cal_score();

}

int main()
{
    input_init();
    simulation();

    cout << score << endl;

    return 0;
}