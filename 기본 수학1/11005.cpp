#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N, B, num;
    stack<int> s;

    cin >> N >> B;
    while (N != 0) {
        s.push(N % B);
        N /= B;
    }
    while (!s.empty()) {
        num = s.top();
        if (num > 9) //아스키코드
            cout << (char) (num + 55);
        else
            cout << num;
        s.pop();
    }
}