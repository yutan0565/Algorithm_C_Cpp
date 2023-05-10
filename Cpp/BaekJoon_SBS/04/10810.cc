#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> num_list(n, 0);
    for(int i=0 ; i < m ; i++)
    {
        int a,b,k;
        cin >> a >> b >> k;
        for(int j = a -1 ; j < b ; j++)
        {
            num_list[j] = k;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << num_list[i] << " ";
    }
    cout << endl;

    return 0;
}