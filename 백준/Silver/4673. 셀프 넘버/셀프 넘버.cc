#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    bool chk[10001] = { false, };

    // 람다 함수를 이용한 d(n) 함수 정의
    auto d = [](int n) {
        int sum = n;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    };

    for (int i = 1; i < 10001; ++i)
        if (d(i) < 10001)
            chk[d(i)] = true;

    for (int i = 1; i < 10001; ++i)
        if (!chk[i])
            cout << i << "\n";

    return 0;
}
