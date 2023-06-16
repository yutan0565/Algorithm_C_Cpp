#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl '\n'
using namespace std;

int n,c;
vector<int> pos_v;

int check_dis(int mid)
{   
    int cnt = 1;
    int before_index = 0;
    for(int i=1 ; i < n ; i ++)
    {   
        int now_index = i; 
        if(pos_v[now_index] - pos_v[before_index] >= mid)
        {
            before_index = now_index;
            cnt += 1;
        }
    }
    return cnt;
}

int bin_search()
{
    int left = 1, right = pos_v[n-1] - pos_v[0];
    int result = - INT_MAX;
    while(left <= right)
    {
        int mid = (left+right)/2;
        int now_cnt = check_dis(mid);
        if(now_cnt >= c) 
        {   
            result = mid;
            left = mid + 1;
        }
        else right = mid -1;
    }
    return result;
}

int main()
{   
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> c;
    for(int i=0 ; i < n ; i++)
    {
        int x; cin >> x;
        pos_v.push_back(x);
    }
    sort(pos_v.begin(), pos_v.end());
    int result = bin_search();
    cout << result << endl;
    return 0;
}