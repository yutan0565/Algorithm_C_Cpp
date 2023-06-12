#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    map<string, bool> enter_m;
    for(int i=0 ; i < n ; i++)
    {
        string str1, str2; cin >> str1 >> str2;
        bool type = true;
        if(str2 == "leave") type = false;
        enter_m[str1] = type;
    }

    vector<string> result;
    for(auto el : enter_m)
    {
        if(el.second) result.push_back(el.first);
    }
    sort(result.rbegin(), result.rend());
    for(auto str : result) cout << str << endl;

    return 0;
}