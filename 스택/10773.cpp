#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K, input, sum = 0;
    stack<int> s;

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> input;
        if (input == 0) //0이면 가장 위에 있던 수 pop으로 뺌
            s.pop();
        else
            s.push(input);
    }
    while (!s.empty()) { //스택에 쌓인 모든 수 더해줌
        sum += s.top();
        s.pop();
    }
    cout << sum;
}