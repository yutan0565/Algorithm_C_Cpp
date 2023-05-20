#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool checkGroupString(string str)
{
    vector<int> al_vec(26,0);
    int prev_index = -1;
    for(int i = 0 ; i < str.size() ; i++)
    {
        int index = int(str[i]) - int('a');
        if(al_vec[index] == 0) al_vec[index] += 1;
        else
        {
            if(index == prev_index) continue;
            else return false;

        }
        prev_index = index;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    int count = 0;
    for(int i=0 ; i<n ; i++)
    {   
        string str; cin >> str;
        if(checkGroupString(str)) count++;
    }
    cout << count << endl;
    return 0;
}