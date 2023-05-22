#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

int main()
{
    int num, b; cin >> num >> b;
    vector<char> asci_v;

    while(num != 0)
    {
        int asci_num = num % b;

        if(asci_num >= 10) asci_num =  asci_num + 'A' - 10;
        else asci_num = asci_num + '0';
        num = num/b;
        asci_v.push_back(char(asci_num));
    }
    reverse(asci_v.begin(), asci_v.end());
    for(int i=0 ; i < asci_v.size() ; i++) cout << asci_v[i];
    cout << endl;

    return 0;
}