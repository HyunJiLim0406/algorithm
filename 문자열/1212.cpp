#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    stack<int> s;

    cin >> str;
    if ((str.size() == 1) && (stoi(str) == 0)) //0처리
        cout << 0;
    else {
        for (int i = str.size() - 1; i >= 0; i--) {
            int tmp = str[i] - '0';
            int cnt = 0;
            while (tmp != 0) { //2로 나누면서 스택에 넣기
                s.push(tmp % 2);
                tmp /= 2;
                cnt++;
            }
            while (cnt != 3) { //3자리가 안된다면 0넣기
                s.push(0);
                cnt++;
            }
        }
        while (!s.top() == 1) //맨 앞 0 제거
            s.pop();
        while (!s.empty()) { //역순 출력
            cout << s.top();
            s.pop();
        }
    }
}