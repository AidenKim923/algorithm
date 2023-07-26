#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> GetFail(const string& strPattern) {
    int iPatternLength = strPattern.length();
    vector<int> vecPi(iPatternLength, 0);

    for (int i = 1, j = 0; i < iPatternLength; ++i) {
        while (j > 0 && strPattern[i] != strPattern[j]) {
            j = vecPi[j - 1];
        }
        if (strPattern[i] == strPattern[j]) {
            vecPi[i] = ++j;
        }
    }
    return vecPi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nLength;
    cin >> nLength;
    string strPattern;
    cin >> strPattern;

    vector<int> vecPi = GetFail(strPattern);
    cout << nLength - vecPi[nLength - 1];
    return 0;
}

