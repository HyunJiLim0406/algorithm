#include <iostream>
#include <stack>
#include <string>
using namespace std;

void bracket(string input, int length) {
    stack<int> s;

    for (int i = 0; i < length; i++) {
        if (input[i] == '(') //왼쪽 괄호면 push
            s.push(1);
        else if (input[i] == ')') { //오른쪽 괄호면 pop인데
            if (s.size() == 0) { //아무것도 없는데 pop 할 수 없음
                cout << "NO\n";
                return;
            }
            s.pop();
        }
    }
    if (s.size() == 0) //스택이 비어있으면 다 짝이 있었다는 뜻
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int n;
    string input;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        int length = input.size();
        bracket(input, length);
    }
}