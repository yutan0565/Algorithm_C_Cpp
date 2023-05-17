#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    int c; cin >> c;
    for(int i = 0 ; i < c ; i++)
    {
        int n; cin >> n;
        double sum = 0, average = 0;
        vector<int> score_v;
        for(int j = 0 ; j < n ; j++)
        {
            int score; cin >> score;
            sum += double(score);
            score_v.push_back(score);
        }
        average = sum/n;
        int count = 0;
        for(int j = 0 ; j < n ; j++)
        {   
            if(double(score_v[j]) > average) count += 1;
        }
        double rate = double(count)/n*100;
        printf("%.3f%%\n", rate);

    }
    return 0;
}