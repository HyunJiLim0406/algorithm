#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N, num;
    string input;
    stack<int> stack;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.compare("push") == 0) {
            cin >> num;
            stack.push(num);
        } else if (input.compare("pop") == 0) {
            if (stack.empty())
                num = -1;
            else {
                num = stack.top();
                stack.pop();
            }
            cout << num << '\n';
        } else if (input.compare("size") == 0)
            cout << stack.size() << '\n';
        else if (input.compare("empty") == 0)
            cout << stack.empty() << '\n';
        else if (input.compare("top") == 0) {
            if (stack.empty())
                cout << -1 << '\n';
            else {
                cout << stack.top() << '\n';
            }
        }
    }
}