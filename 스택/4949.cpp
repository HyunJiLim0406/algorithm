#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void bracket(char* input, int length) {
    stack<char> s;

    for (int i = 0; i < length; i++) {
        if (input[i] == '(' || input[i] == '[') //왼쪽 괄호면 push
            s.push(input[i]);
        else if (input[i] == ')'){ //오른쪽 괄호면 pop인데
            if (s.size() == 0 || s.top() != '(') { //아무것도 없거나 짝 안맞는지 확인
                cout << "no\n";
                return;
            }
            s.pop();
        }
        else if (input[i] == ']') { //위와 같음
            if (s.size() == 0 || s.top() != '[') {
                cout << "no\n";
                return;
            }
            s.pop();
        }
    }
    if (s.size() == 0) //스택이 비어있으면 다 짝이 있었다는 뜻
        cout << "yes\n";
    else
        cout << "no\n";
}

int main() {
    char input[101];

    while (true) {
        cin.getline(input, 101); //띄어쓰기까지 받는 방법
        if (!strcmp(input, "."))
            break;
        bracket(input, strlen(input));
    }
}