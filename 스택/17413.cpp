#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    stack<char> s;
    bool isTag = false, isChar = false;

    getline(cin, str);
    str += ' ';
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '<': //isTag를 true로 하고 스택에 쌓였던 값들 출력
                isTag = true;
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << str[i];
                break;
            case '>': //isTag를 false로
                isTag = false;
                cout << str[i];
                break;
            case ' ': //isTag일 때는 그냥 출력하고 아닐 때는 스택 출력해서 단어 뒤집기
                if (isTag)
                    cout << str[i];
                else {
                    while (!s.empty()) {
                        cout << s.top();
                        s.pop();
                    }
                    cout<<' ';
                }
                break;
            default: //문자라는 뜻
                isChar = true;
                break;
        }
        if (isChar) {
            if (isTag) //isTag일 때는 그냥 출력
                cout << str[i];
            else //isTag가 아닐 때는 스택에 쌓기
                s.push(str[i]);
            isChar = false;
        }
    }
}