#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

#define MAX_LEN 51
#define MAX_BALL 51*51

struct FIREBALL
{
    int x;
    int y;
    int weight;
    int speed;
    int direct;
};

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int same_direct[4] = {0,2,4,6};
int other_direct[4] = {1,3,5,7};

int n,m,k;
vector<FIREBALL> graph[MAX_LEN][MAX_LEN];
vector<FIREBALL> fireball_v;
 
void graph_init()
{
    cin >> n >> m >> k;
    for(int i=0 ; i < m ; i++)
    {   // 질량 , 방향, 속력
        int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
        a -= 1; b -= 1;
        FIREBALL temp_fireball = {a,b,c,d,e};
        graph[a][b].push_back(temp_fireball);
        fireball_v.push_back(temp_fireball);
    }
}

void move_fireball()
{
    // 기존 위치 초기화
    for(int i=0 ; i < n ; i ++)
    {
        for(int j=0 ; j < n ; j++)
        {                 
            graph[i][j].clear();
        }
    }

    // 모든 파이어볼 이동
    for(int i=0 ; i < fireball_v.size() ; i++)
    {
        FIREBALL now_fireball = fireball_v[i];
        int now_x = now_fireball.x;
        int now_y = now_fireball.y;
        int now_weight = now_fireball.weight;
        int now_speed = now_fireball.speed;
        int now_direct = now_fireball.direct;

        // 새로운 위치 선정
        int temp_speed = now_speed%n;
        int nx = now_x + dx[now_direct]*temp_speed;
        int ny = now_y + dy[now_direct]*temp_speed;
        // 위치 조정
        if(nx < 0) nx += n;
        else if(nx >= n) nx %= n;
        if(ny < 0) ny  += n;
        else if(ny >= n) ny %= n;

        // now_speed = now_speed%n; // 양수
        // int nx = (now_x + dx[now_direct]*now_speed+n)%n; 
        // int ny = (now_y + dy[now_direct]*now_speed+n)%n;

        FIREBALL new_fireball = {nx,ny,now_weight,now_speed,now_direct};
        graph[nx][ny].push_back(new_fireball);
        fireball_v[i] = new_fireball;
    }
}

void sum_fireball()
{
    vector<FIREBALL> new_fireball_v;

    for(int i=0 ; i < n ; i ++)
    {
        for(int j=0 ; j < n ; j++)
        {
            // 아무것도 없는 경우
            if(graph[i][j].size() == 0) continue;;
            // 한개만 존재하는 경우
            if(graph[i][j].size() == 1)
            {
                new_fireball_v.push_back(graph[i][j][0]);
                continue;
            }
            // 여러개가 있는 경우
            int weight_sum = 0;
            int speed_sum = 0;
            int cnt = graph[i][j].size();

            bool odd = true;
            bool even = true;

            for(int p=0 ; p < graph[i][j].size() ; p++)
            {
                weight_sum += graph[i][j][p].weight;
                speed_sum += graph[i][j][p].speed;
                // 만약 짝수면,  odd를 false로
                if(graph[i][j][p].direct %2 == 0) odd = false;
                else even = false;
            }

            int new_weight = weight_sum / 5;
            int new_speed = speed_sum / cnt;
            // 만약 새로운 weight가 0이면 그냥 사라짐
            if(new_weight == 0 ) continue;
            // 둘짝 홀,짝 / odd, even 인 경우는 0,2,4,6 으로 방향 결정
            if(odd == true || even == true )
            {
                for(int p=0 ; p < 4 ; p++)
                {
                    FIREBALL new_fireball = {i,j,new_weight, new_speed, same_direct[p]};
                    new_fireball_v.push_back(new_fireball);
                }
            }
            // 방향이 다르면, 1,3,5,7
            else
            {
                for(int p=0 ; p < 4 ; p++)
                {
                    FIREBALL new_fireball = {i,j,new_weight, new_speed, other_direct[p]};
                    new_fireball_v.push_back(new_fireball);
                }
            }
        }
    }

    // 새로운 fireball들의 위치 업데이트
    fireball_v = new_fireball_v;
}

void simulation()
{
    for(int i=0 ; i < k ; i++)
    {
        // 파이어볼 이동
        move_fireball();
        // 합치기
        sum_fireball();
    }

}

int count_fireball()
{
    int result = 0;
    for(int i=0 ; i < fireball_v.size() ; i ++)
    {
        result += fireball_v[i].weight;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    graph_init();
    simulation();

    int result = count_fireball();
    cout << result << endl;

    return 0;
}