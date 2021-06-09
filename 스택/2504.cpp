#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    int result = 0;

    cin >> str;
    stack<char> bracket;
    stack<int> num;
    for (char &i : str) {
        if (i == '(' || i == '[') { //여는 괄호
            bracket.push(i);
            num.push(1);
        } else {
            if (bracket.empty() || (i == ')' && bracket.top() != '(') ||
                (i == ']' && bracket.top() != '[')) { //스택이 비어있거나 괄호 짝이 맞지 않음
                cout << 0;
                return 0;
            }
            bracket.pop();
            int tmp = 0;
            while (num.top() != 1) { //(X), [X]에서 X를 계산
                tmp += num.top();
                num.pop();
            }
            num.pop();
            tmp += (tmp == 0) ? 1 : 0; //(), [] 일 수도 있음
            tmp = (i == ')') ? tmp * 2 : tmp * 3; // ')'면 2를 곱하고 ']'면 3을 곱함
            num.push(tmp);
        }
    }
    if (!bracket.empty()) { //괄호가 남아있음
        cout << 0;
        return 0;
    }
    while (!num.empty()) { //결과 더하기
        result += num.top();
        num.pop();
    }
    cout << result;
}