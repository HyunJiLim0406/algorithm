#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    stack<char> s1, s2;
    int M;
    char command, input_char, tmp;

    cin >> input;
    for (int i = 0; i < input.size(); i++)
        s1.push(input[i]);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> command;
        switch (command) {
            case 'L': //s1의 top을 s2에 push
                if (!s1.empty()) {
                    tmp = s1.top();
                    s1.pop();
                    s2.push(tmp);
                }
                break;
            case 'D': //s2의 top을 s1에 push
                if (!s2.empty()) {
                    tmp = s2.top();
                    s2.pop();
                    s1.push(tmp);
                }
                break;
            case 'B': //s1의 top 삭제
                if (!s1.empty())
                    s1.pop();
                break;
            case 'P': //s1에 push
                cin >> input_char;
                s1.push(input_char);
                break;
        }
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty()) { //s2 출력
        cout << s2.top();
        s2.pop();
    }
}