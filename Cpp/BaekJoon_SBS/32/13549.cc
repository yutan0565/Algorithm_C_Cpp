#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

#define endl '\n'
using namespace std;

#define MAX_POINT 100001*2

int n,k;
vector<int> visited(MAX_POINT, INT_MAX);

int daik(int start, int end)
{
    int result = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    visited[start] = 0;

    while(!pq.empty())
    {
        int dis = -pq.top().first;
        int a = pq.top().second;
        if(a == end) 
        {
            result = visited[a];
            break;
        }
        pq.pop();
        for(int i = 0 ; i < 3 ; i++)
        {   
            int nx, new_dis;
            if(i == 0)
            {
                nx = a + 1;
                new_dis = dis + 1;
            }
            else if(i == 1)
            {
                nx = a - 1;
                new_dis = dis + 1;
            }
            else
            { 
                nx = 2*a;
                new_dis = dis;
            }

            if(0<=nx && nx <= 2*k+1)
            {
                if(visited[nx] > new_dis)
                {
                    visited[nx] = new_dis;
                    pq.push(make_pair(-new_dis, nx));
                }
            }
        }
    }

    return result;
}


int main()
{
    cin >> n >> k;
    int result = daik(n,k);

    if(n < k) cout << result << endl;
    else if (n == k) cout << 0 << endl;
    else cout << n-k << endl;

    return 0;
}