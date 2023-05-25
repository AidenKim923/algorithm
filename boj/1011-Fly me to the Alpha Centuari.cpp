#include <iostream>
#include <cmath>

using namespace std;
// 고려한 과정
// 두 지점 사이의 거리를 계산
// 이동 거리의 합이 두 지점 사이의 거리보다 처음으로 커지는 순간을 찾아야함
// 해당 순간까지 이동한 횟수를 더함
// 만약 두 지점 사이의 거리와 이동거리의 합이 같으면 이동한 횟수가 최소한 작동횟수
// 합이 다르면 추가로 이동해야해서 +1을 해줌.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, y;
        cin >> x >> y;

        int distance = y - x;

        int k = static_cast<int>(sqrt(distance));

        if (k * k == distance) {
            cout << 2 * k - 1 << endl;
        }
        else if (distance <= k * k + k) {
            cout << 2 * k << endl;
        }
        else {
            cout << 2 * k + 1 << endl;
        }
    }

    return 0;
}

