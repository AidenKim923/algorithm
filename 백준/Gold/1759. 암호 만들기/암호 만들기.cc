#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int L, C;

// 모음 문자를 저장하는 세트
const set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

// DFS 방식 풀이
void dfs(const vector<char>& v, int now, string str, int conso, int vowel)
{
    str += v[now];  // 현재 문자 추가
    // 현재 문자가 모음인지 검사
    if (vowels.count(v[now]) > 0) vowel++;
    else conso++;
    
    if (str.length() == L) {
        if (vowel >= 1 && conso >= 2)
            cout << str << '\n';
        return;
    }
    // 다음 문자로 진행
    for (int i = now + 1; i < C; ++i) {
        dfs(v, i, str, conso, vowel);
    }
}

int main()
{
    cin >> L >> C;
    vector<char> v(C);
    for (char& c : v) cin >> c;
    sort(v.begin(), v.end());
    
    for (int i = 0; i <= C - L; ++i) {
        dfs(v, i, "", 0, 0);
    }
    
    return 0;
}

