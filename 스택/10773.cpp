#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K, input, sum = 0;
    stack<int> s;

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> input;
        if (input == 0) { //0이면 맨 위 숫자 가져오고 pop 한 뒤 sum에서 뺌
            int num = s.top();
            s.pop();
            sum -= num;
        }
        else { //0이 아니면 더해주고
            s.push(input);
            sum += input;
        }
    }
    cout << sum;
}