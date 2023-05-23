#include <iostream>

#define endl '\n'
using namespace std;

int main()
{
    int num; cin >> num;
    int last_num = 1;
    int count = 0;

    while(true)
    {
        if(num <= last_num) 
        {
            cout << count+1 << endl;
            break;
        }
        count += 1;
        last_num += (count*6);
    }
    return 0;
}