#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

int main()
{   
    string str1;
    string str2;
    cin >> str1 >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int result_len = max(str1.length(), str2.length()) + 1;

    vector<int> num_1_v(result_len, 0);
    vector<int> num_2_v(result_len, 0);
    vector<int> result(result_len, 0);


    int str1_len = str1.length();
    int str2_len = str2.length();

    for(int i = 0 ; i < str1_len ; i++)
        num_1_v[i] = str1[i] - '0';

    for(int i = 0 ; i < str2_len ; i++)
        num_2_v[i] = str2[i] - '0';
    
    for(int i = 0 ; i < result_len-1 ; i++)
    {
        result[i] = result[i] + num_1_v[i] + num_2_v[i];
        if(result[i] >= 10)
        {
            result[i+1] += 1;
            result[i] %= 10;
        }
    }

    reverse(result.begin(), result.end());

    if(result[0] != 0) cout << result[0];
    for(int i = 1 ; i < result_len ; i++) 
    {   
        cout << result[i];
    }

    return 0;
}