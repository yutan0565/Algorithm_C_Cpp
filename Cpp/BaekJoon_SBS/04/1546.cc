#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

double getAverage(vector<double> v)
{
    double result = 0.0;
    double sum = 0.0;
    for(int i=0 ; i < v.size() ; i++) sum += v[i];
    result = sum / v.size();
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<double> score_vector;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin >> x;
        score_vector.push_back(x);
    }
    int max_score = *max_element(score_vector.begin(), score_vector.end());
    for(int i=0 ; i<n ; i++)
    {
        score_vector[i] = score_vector[i]/max_score*100;
    }


    double result = getAverage(score_vector);
    cout << result << endl;
    return 0;
}