#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num_list;
    int x;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x;
        num_list.push_back(x);
    }

    int v;
    cin >> v;
    int count = 0;
    for(int i = 0 ; i < num_list.size() ; i++)
    {   
        if(num_list[i] == v) count++;
    }

    cout << count << endl;
    return 0;
}