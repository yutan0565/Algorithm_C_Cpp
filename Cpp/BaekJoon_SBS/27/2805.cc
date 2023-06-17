#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define ll long long
#define MAX_LEN LONG_LONG_MAX
using namespace std;

ll n,m;
vector<ll> num_v;

ll check_cut(ll mid)
{
    ll cut =0 ;
    for(int i=0 ; i < n ; i ++)
    {
        if(mid >= num_v[i]) continue;
        cut += (ll)(num_v[i] - mid);
    }   
    return cut;
}

ll bin_search()
{
    ll left=0, right = MAX_LEN;
    ll max_cut = -MAX_LEN;
    while(left <= right)
    {
        ll mid = (left+right)/2;
        ll now_cut = check_cut(mid);
        // 아직 부족함
        if(now_cut < m)
        {
            right = mid -1;
        }
        // 만족하는 경우
        else
        {
            max_cut = max(max_cut, mid);
            left = mid + 1;
        }
    }
    return max_cut;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0 ; i < n ; i ++)
    {
        ll num; cin >> num;
        num_v.push_back(num);
    }

    sort(num_v.begin(), num_v.end());

    ll result = bin_search();
    cout << result << endl;

    return 0;
}