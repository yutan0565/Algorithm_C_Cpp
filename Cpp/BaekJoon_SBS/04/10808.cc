#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num_list;

    for(int i=0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        num_list.push_back(x);
    }

    int min_value = *min_element(num_list.begin(), num_list.end());
    int max_value = *max_element(num_list.begin(), num_list.end());

    cout << min_value << " " << max_value << endl;

    return 0;
}