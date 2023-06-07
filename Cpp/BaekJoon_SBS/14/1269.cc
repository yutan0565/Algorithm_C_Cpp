#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl '\n'
using namespace std;
int n,m;
set<int> num_s;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0 ; i < n; i++)
    {
        int num; cin >> num;
        num_s.insert(num);
    }

    for(int i=0 ; i < m; i++)
    {
        int num; cin >> num;
        if(num_s.find(num) == num_s.end()) num_s.insert(num);
        else num_s.erase(num);
    }

    cout << num_s.size() << endl;

    return 0;
}