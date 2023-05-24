#include <iostream>
#include <cmath>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
    string str;
    int b;
    cin >> str >> b;

    int sum = 0;
    int num_len = str.length();
    for (int i = 0; i < num_len; i++)
    {   
        int asci_num = str[num_len - (i + 1)];
        if ('0' <= asci_num && asci_num <= '9') asci_num = asci_num - '0';
        else asci_num = asci_num + 10 - 'A';
        sum += (asci_num * (int)pow(b, i));
    }
    cout << sum << endl;

    return 0;
}