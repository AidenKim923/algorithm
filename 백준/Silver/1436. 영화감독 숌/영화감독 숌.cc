#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int num = 666, count = 0;
    
    while (true) {
        // 666이 포함되어 있는지 확인
        if (to_string(num).find("666") != string::npos)
        {  
            count++;
        }
        // N번째 종말의 숫자를 찾았다면
        if (count == N)
        {  
            cout << num << endl;
            break;
        }
        num++;
    }
    
    return 0;
}

