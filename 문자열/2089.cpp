#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int num;
    stack<int> s;

    cin >> num;
    if (num == 0)
        cout << 0;
    else {
        while (num != 0) {
            int tmp = num % (-2);
            num /= (-2);
            if (tmp == -1) { //나머지는 0 or 1
                s.push(1);
                num++;
            } else
                s.push(tmp);
        }
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
}