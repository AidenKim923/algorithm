#include <string>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

void toLower(string str, unordered_map<string, int>& um) 
{
	for (auto& c: str) c = tolower(c);
    for (int i = 0; i < str.size() - 1; i++) {
        if (!isalpha(str[i]) || !isalpha(str[i + 1])) continue;// 알파벳이 아니라면 넘긴다.
        um[str.substr(i, 2)]++;// 데이터 저장
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    int intersection = 0; // 교집합
    int unionNum = 0; // 합집합
    unordered_map<string, int> um1, um2;
    toLower(str1, um1);
    toLower(str2, um2);

    for (auto& i : um1)
    {
        // 교집합 개수 증가
        if (um2[i.first])
        {
            intersection += min(i.second, um2[i.first]);
            um2[i.first] = max(i.second, um2[i.first]);
        }
        else
        {
            um2[i.first] = i.second;
        }
    }
    // 합집합 크기 계산
    for (auto& i : um2)
    {
		unionNum += i.second;
	}
    if (unionNum == 0) return 65536;
	answer = floor((double)intersection / unionNum * 65536);
	return answer;
}
