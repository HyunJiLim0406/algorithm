#include <iostream>
#include <stack>
#include <string>

using namespace std;

string findPw(string str) {
    string result = "";
    stack<char> s1, s2;

    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '<': //왼쪽으로 커서 이동
                if (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                break;
            case '>': //오른쪽으로 커서 이동
                if (!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
                break;
            case '-': //문자 삭제
                if (!s1.empty())
                    s1.pop();
                break;
            default: //문자 입력
                s1.push(str[i]);
                break;
        }
    }
    while (!s1.empty()) { //s1의 값들 다 옮겨주기
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty()) { //result에 저장
        result += s2.top();
        s2.pop();
    }
    return result;
}

int main() {
    int T;
    string str;

    cin >> T;
    while (T--) {
        cin >> str;
        cout << findPw(str) << '\n';
    }
}