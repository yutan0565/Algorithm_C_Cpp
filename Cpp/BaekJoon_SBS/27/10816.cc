#include <iostream>
#include <map>
#include <algorithm>

#define endl '\n'
using namespace std;
int n,m;
map<int,int> num_m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0 ; i < n ; i++)
    {
        int num; cin >> num;
        num_m[num] += 1;
    }

    cin >> m;
    for(int i=0 ; i < m ; i++)
    {
        int target; cin >> target;
        cout << num_m[target] << " ";
    }
    cout << endl;
    return 0;
}