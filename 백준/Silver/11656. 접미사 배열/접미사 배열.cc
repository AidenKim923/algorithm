#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	string S;
	vector<string> v;

	cin >> S;
	// 접미사 저장
	for (int i = 0; i < S.size(); i++) {
		string tmp = S.substr(i, S.size() - i);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}

