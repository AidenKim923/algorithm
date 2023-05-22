#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long count_colorful_subsequences(int N, int K, const vector<int>& A) {
    long long count = 0;
    int left = 0, right = 0;
    vector<int> freq_map(K + 1, 0);
    int distinct_count = 0;

    while (right < N) {
        freq_map[A[right]]++;
        if (freq_map[A[right]] == 1) {
            distinct_count++;
        }

        while (distinct_count == K) {
            count += N - right;
            freq_map[A[left]]--;
            if (freq_map[A[left]] == 0) {
                distinct_count--;
            }
            left++;
        }
        right++;
    }
    return count;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        long long result = count_colorful_subsequences(N, K, A);
        cout << "#" << test_case << " " << result << '\n';
    }

    return 0;
}

