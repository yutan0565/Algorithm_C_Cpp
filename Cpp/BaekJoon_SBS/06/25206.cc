#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void defineScoreMap(map<string,double> &score_map)
{
    score_map["A+"] = 4.5;
    score_map["A0"] = 4.0;
    score_map["B+"] = 3.5;
    score_map["B0"] = 3.0;
    score_map["C+"] = 2.5;
    score_map["C0"] = 2.0;
    score_map["D+"] = 1.5;
    score_map["D0"] = 1.0;
    score_map["F"] = 0.0;
}

int main()
{   
    map<string,double> score_map;
    defineScoreMap(score_map);
    double score_sum =0, grade_sum = 0,aver;
    for(int i=0 ; i <20 ; i++)
    {
        string name; float grade; string type;
        cin >> name >> grade >> type;
        if(type == "P") continue;
        score_sum += (grade*score_map[type]); grade_sum += grade;
    }
    aver = score_sum/grade_sum;
    cout << aver << endl;

    return 0;
}