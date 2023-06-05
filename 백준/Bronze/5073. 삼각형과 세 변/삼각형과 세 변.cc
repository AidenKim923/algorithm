#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin.tie(0);
    while (true) {
        for ( int i = 0; i < 3; i++ ) {
            cin >> arr[i];
        }

        if ( arr[0] == 0 && arr[0] == arr[1] && arr[0] == arr[2] ) break;

        sort(arr, arr + 3);
        if ( arr[2] >= arr[1] + arr[0]) cout << "Invalid" << endl;
        else if ( arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2])  cout << "Scalene" << endl;
        else {
            if ( arr[0] == arr[1] && arr[1] == arr[2] ) {
                cout << "Equilateral" << endl;
            } else {
                cout << "Isosceles" << endl;
            }
        }
    }

    return 0;
}

