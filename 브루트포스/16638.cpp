#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

vector<bool> pri;

int calc(int num1, int num2, char op) { //계산
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
    return 0;
}

int calcString(string exp) {
    deque<char> op_q;
    deque<int> num_q;
    for (int i = 0; i < exp.size(); i++) {
        if (isdigit(exp[i])) //숫자 덱에 넣기
            num_q.push_back(exp[i] - '0');
        else { //연산자일 때
            if (pri[i / 2]) { //먼저 계산해야 하면
                int tmp = calc(num_q.back(), exp[i + 1] - '0', exp[i]); //계산
                num_q.pop_back();
                num_q.push_back(tmp);
                i++;
            } else //그렇지 않다면 그냥 덱에 넣기
                op_q.push_back(exp[i]);
        }
    }
    int size = op_q.size();
    for (int i = 0; i < size; i++) {
        char op = op_q.front();
        op_q.pop_front();
        if (op == '*') { //곱셈 계산
            int num1 = num_q.front();
            num_q.pop_front();
            int num2 = num_q.front();
            num_q.pop_front();
            num_q.push_front(calc(num1, num2, op));
        } else { //그냥 이동
            op_q.push_back(op);
            num_q.push_back(num_q.front());
            num_q.pop_front();
        }
    }
    num_q.push_back(num_q.front());
    num_q.pop_front();

    int result = num_q.front();
    num_q.pop_front();
    while (!num_q.empty()) {
        result = calc(result, num_q.front(), op_q.front()); //앞에서부터 계산
        num_q.pop_front();
        op_q.pop_front();
    }
    return result;
}

int main() {
    int N, size, result = INT32_MIN;
    string expression;

    cin >> N >> expression;
    size = N / 2;
    pri.assign(size, false);
    for (int i = 0; i < (1 << size); i++) { //비트마스킹
        bool isBracketed = false, isPromise = true;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) { //1일 때
                if (isBracketed) { //연속된 괄호라면 불가능
                    isPromise = false;
                    break;
                }
                pri[j] = true;
                isBracketed = true;
            } else {
                pri[j] = false;
                isBracketed = false;
            }
        }
        if (!isPromise) //연속된 괄호였음
            continue;
        result = max(result, calcString(expression)); //최댓값 갱신
    }
    cout << result;
}