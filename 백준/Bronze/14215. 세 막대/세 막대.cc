#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int stick[3];
    cin.tie(0);
    for (int i = 0; i < 3; i++) {
        cin >> stick[i];
    }
    sort(stick, stick + 3);
    
    while (true) {
        if (stick[2] < stick[1] + stick[0]) {
            cout << stick[2] + stick[1] + stick[0] << endl;
            
            return 0;
        }
        stick[2]--;
    }
}

