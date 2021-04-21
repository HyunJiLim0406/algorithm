#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int T;

    cin >> T;
    cin.ignore(); //버퍼 비우기
    for (int i = 0; i < T; i++) {
        string input;
        stack<char> s;

        getline(cin, input); //띄어쓰기 포함 입력
        input += ' '; //마지막 문자 출력 위해 덧붙임
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == ' ') { //띄어쓰기면 출력
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            } else //아니면 스택에 투입
                s.push(input[j]);
        }
    }
}