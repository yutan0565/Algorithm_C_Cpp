#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string input;
    cin >> input;
    int sum = 0;
    for(int i=0 ; i < input.length() ; i++) sum += ((int)(input[i]) - (int)('0'));
    cout << sum << endl;
    return 0;
}