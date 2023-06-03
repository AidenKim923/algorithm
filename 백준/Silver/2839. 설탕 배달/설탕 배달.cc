#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count_5 = N / 5;
    int remaining = N % 5;

    while (count_5 >= 0)
    {
        if (remaining % 3 == 0)
        {
            int count_3 = remaining / 3;
            cout << count_5 + count_3 << endl;
            return 0;
        }
        // 남은 설탕 무게가 3의 배수가 아닌 경우
        count_5--;
        remaining += 5;
    }
    // 정확히 N킬로그램을 만들 수 없는 경우
    cout << -1 << endl;  

    return 0;
}