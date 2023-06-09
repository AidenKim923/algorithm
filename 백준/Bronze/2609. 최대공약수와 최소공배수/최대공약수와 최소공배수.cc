#include <iostream>

using namespace std;

// 최대공약수를 계산하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수를 계산하는 함수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';

    return 0;
}