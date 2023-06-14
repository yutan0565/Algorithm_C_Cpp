#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 100005
#define endl '\n'
#define ll long long
using namespace std;

ll n,k;

ll check(ll mid)
{
    ll cnt = 0;
    for(int i=1 ; i < n+1 ; i++)
    {
        cnt += min(n, (ll)(mid/i));
        if(i > mid) break;
    }
    return cnt;
}


ll bin_search()
{
    ll left =1, right = n*n;
    ll result = -1;

    while(left <= right)
    {
        ll mid = (left + right)/2;
        ll temp_cnt = check(mid);
        if(temp_cnt < k) left = mid + 1;
        else
        {
            result = mid;
            right = mid -1;
        }
    }
    return result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    ll result = bin_search();
    cout << result << endl;



    return 0;
}