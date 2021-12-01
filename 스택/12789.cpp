#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, input, idx = 1;
    stack<int> s;

    cin >> n;
    while (n--) {
        cin >> input;
        if (input == idx) { //바로 줄 설 수 있음
            idx++;
            continue;
        }
        while (!s.empty() && s.top() == idx) { //스택으로 옮겨간 사람들 줄 서기
            s.pop();
            idx++;
        }
        s.push(input); //스택에 넣기
    }
    while (!s.empty()) { //남아있는 사람들 확인
        if (s.top() != idx) {
            cout << "Sad";
            return 0;
        }
        s.pop();
        idx++;
    }
    cout << "Nice";
}