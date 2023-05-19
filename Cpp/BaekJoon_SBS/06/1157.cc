#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    string str;
    cin >> str;
    vector<int> al_v(26,0);
    for(int i = 0 ; i<str.size() ; i++)
    {
        int index = str[i];
        if(int('a') <= index & index <=int('z')) index -= int('a');
        else index -= int('A');
        al_v[index] += 1;
    }

    int max_value = *max_element(al_v.begin(), al_v.end());
    int max_idnex = max_element(al_v.begin(), al_v.end()) - al_v.begin();
    int same_count = count(al_v.begin(), al_v.end(), max_value);

    if(same_count == 1) cout << (char(max_idnex + int('A'))) << endl;
    else cout << '?' << endl;


    return 0;
}