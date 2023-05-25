#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; // 

    vector<int> arr(n);
    // 숫자의 빈도를 저장할 map 선언
    map<int, int> freq; 

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++; // 빈도 map에 해당 숫자의 빈도를 증가
    }

    // 평균 계산
    double avg = 0;
    for (auto num : arr)
    {
        avg += num;
    }
    avg /= n;

    // 정렬을 통해 중앙값과 범위를 구한다
    sort(arr.begin(), arr.end());
    int median = arr[n / 2]; // 중앙값
    int range = arr[n - 1] - arr[0]; // 범위

    // 최빈값을 구한다
    int mode = 0;
    int max_freq = 0;
    bool second = false;

    for (auto& elem : freq)
    {
        // 최대 빈도가 같을 때, 두 번째 최빈값을 구한다
        if (max_freq == elem.second)
        {
            if (!second)
            {
                mode = elem.first;
                second = true;
            }
        }

        // 최대 빈도가 현재 elem.second보다 작을 때
        if (max_freq < elem.second)
        {
            max_freq = elem.second;
            mode = elem.first;
            // 두 번째 최빈값을 다시 false로 설정
            second = false; 
        }
    }

    cout << round(avg) << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
