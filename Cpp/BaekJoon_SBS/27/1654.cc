#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl '\n'
#define ll long long
using namespace std;
ll k,n;
vector<ll> num_v;

ll cutLine(ll mid)
{
    ll sum=0;
    for(int i=0 ; i < k ; i++)
    {
        ll temp = num_v[i] / mid;
        sum += temp;
    }
    return sum;
}

int bin_search()
{
    ll left=1, right = INT_MAX;
    ll max_cut = INT_MIN;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        ll line_cnt = cutLine(mid);

        // 개수가 부족한 경우 -> 줄여야함
        if(line_cnt < n)  right = mid - 1;
        // n 개 이상인 경우 -> 늘려야함
        else 
        {
            max_cut = max(mid, max_cut);
            left = mid + 1;
        }
    }
    return max_cut;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> n;
    for(int i=0 ; i < k ; i ++)
    {
        ll num; cin >> num;
        num_v.push_back(num);
    }

    ll result = bin_search();
    cout << result << endl;


    return 0;
}