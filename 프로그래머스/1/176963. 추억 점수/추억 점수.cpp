#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> yearningmap;
    
    for (int i = 0; i < name.size(); ++i)
    {
        yearningmap[name[i]] = yearning[i];
    }

    for (auto p : photo)
    {
        int yearning = 0;
        for (auto person : p)
        {
            yearning += yearningmap[person];
        }
        answer.push_back(yearning);
    }

    return answer;
}