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
    cin >> n;

    vector<int> arr(n);
    map<int, int> freq; 

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++; 
    }

    double avg = 0;
    for (auto num : arr)
    {
        avg += num;
    }
    avg /= n;

    sort(arr.begin(), arr.end());
    int median = arr[n / 2]; 
    int range = arr[n - 1] - arr[0]; 

    // 최빈값을 구한다
    int mode = 0;
    int max_freq = 0;
    int cnt = 0;

    for (auto& elem : freq)
    {
        // 최대 빈도가 현재 elem.second보다 작을 때
        if (max_freq < elem.second)
        {
            max_freq = elem.second;
            mode = elem.first;
            cnt = 0;
        }
        // 최대 빈도가 같을 때, 두 번째로 작은 최빈값을 구한다
        else if (max_freq == elem.second)
        {
            if (cnt == 0)
            {
                mode = elem.first;
                cnt++;
            }
        }
    }

    cout << round(avg) << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
