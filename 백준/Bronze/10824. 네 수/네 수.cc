#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B, C, D;
	cin >> A >> B >> C >> D;

	string AB = A + B;
	string CD = C + D;
	long long result = stoll(AB) + stoll(CD);
	cout << result << endl;

	return 0;
}