#include <iostream>

using namespace std;

int main() {
    int N, M, temp;
    cin >> N >> M;

    int a[100][100] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> temp;
                a[j][k] += temp;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

