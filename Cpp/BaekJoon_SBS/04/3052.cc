#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> remain_set;
    for(int i=0 ; i<10 ;i++) 
    {   
        int x;
        cin >> x;
        int remain = x % 42;
        remain_set.insert(remain);
    }
    cout << remain_set.size() << endl;

    return 0;
}