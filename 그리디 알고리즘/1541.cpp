#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int calc(string expression, int start, int end) {
    int sum = 0;
    vector<int> num_arr;
    stack<int> num_stack;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '-' || expression[i] == '+' || i == end) { //op 또는 배열의 끝이면 스택에 쌓인 수를 빼서 가공
            int temp = 0;
            int mul = 1;
            while (!num_stack.empty()) {
                temp += (num_stack.top() * mul);
                num_stack.pop();
                mul *= 10;
            }
            num_arr.push_back(temp);
        } else //숫자를 스택에 넣어줌
            num_stack.push(expression[i] - '0');
    }
    for (int i = 0; i < num_arr.size(); i++) //배열에 쌓인 수를 모두 더함
        sum += num_arr[i];
    return sum;
}

int bracket(string expression) {
    int length = expression.size();
    int minus_point = 60;

    for (int i = 0; i < length; i++) {
        if (expression[i] == '-') { //마이너스가 처음 등장하면 그 기준으로 이전 식을 전부 더한 것과 이후 식을 전부 더한 것을 빼면 됨
            minus_point = i;
            break;
        }
    }
    if (minus_point == 60) //식에 마이너스가 없을 수도 있음
        return calc(expression, 0, length);
    else //마이너스를 기준으로 앞 뒤를 나누어 더하고 서로 빼줌
        return calc(expression, 0, minus_point) - calc(expression, minus_point + 1, length);
}

int main() {
    string expression;

    cin >> expression;
    cout << bracket(expression);
}