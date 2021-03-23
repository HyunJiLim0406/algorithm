#include <iostream>
#include <cstring>
using namespace std;

int calc(char* expression, int start, int end) {
    int num_cnt = 0, stack_cnt = 0, sum = 0;
    int num_arr[51] = { 0, };
    int num_stack[5] = { 0, };

    for (int i = start; i <= end; i++) {
        if (expression[i] == '-' || expression[i] == '+' || i == end) { //op 또는 배열의 끝이면 스택에 쌓인 수를 빼서 가공
            int temp = 0;
            int mul = 1;
            for (int j = stack_cnt - 1; j >= 0; j--) {
                temp = temp + (num_stack[j] * mul);
                mul *= 10;
            }
            num_arr[num_cnt++] = temp; //가공한 수를 배열에 넣어줌
            stack_cnt = 0;
        }
        else //숫자를 스택에 넣어줌
            num_stack[stack_cnt++] = expression[i] - '0';
    }
    for (int i = 0; i < num_cnt; i++) //배열에 쌓인 수를 모두 더함
        sum += num_arr[i];
    return sum;
}

int bracket(char* expression) {
    int length = strlen(expression);
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
    char m_expression[51];

    cin >> m_expression;
    cout << bracket(m_expression);
}