#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> num_list(30,0);

    for(int i = 0 ; i < 28 ; i ++)
    {
        int x;
        cin >> x;
        num_list[x-1] = 1;
    }
    for(int i = 0 ; i < num_list.size() ; i++)
    {
        if(!num_list[i]) cout << i+1 << endl;
    }
    return 0;
}