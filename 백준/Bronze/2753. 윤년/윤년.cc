#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        cout << 1 << endl;  // 윤년일 경우
    }
    else
    {
        cout << 0 << endl;  // 윤년이 아닐 경우
    }
    
    return 0;
}

