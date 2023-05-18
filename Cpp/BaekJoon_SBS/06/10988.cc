#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{   
    string str, r_str;
    cin >> str;
    r_str.resize(str.size());
    copy(str.rbegin(), str.rend(), r_str.begin());
    if(str == r_str) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}