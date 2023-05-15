#include <string>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i =0 ; i < t ; i++)
    {
        int r;
        cin >> r;
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j ++)
        {
            for(int k = 0 ; k < r ; k++) cout << input[j];
        }
        cout << endl;
    }
    return 0;
}