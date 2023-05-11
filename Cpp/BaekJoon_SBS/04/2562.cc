#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> num_list;
    for(int i=0 ; i < 9 ; i++)
    {
        int x;
        cin >> x;
        num_list.push_back(x);
    }

    int max_value = *max_element(num_list.begin(), num_list.end());
    int max_index = max_element(num_list.begin(), num_list.end()) - num_list.begin();

    cout << max_value << endl << max_index+1 << endl;
    return 0;
}