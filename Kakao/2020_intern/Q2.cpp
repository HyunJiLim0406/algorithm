#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int op_pri[3] = {1, 2, 3}; //+, -, *
vector<char> op;
vector<ll> num;

char nowOp(int pri) { //이번에 할 연산
    for (int i = 0; i < 3; i++) {
        if (op_pri[i] == pri) {
            switch (i) {
                case 0:
                    return '+';
                case 1:
                    return '-';
                case 2:
                    return '*';
            }
        }
    }
}

ll calc(ll num1, ll num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
}

ll findMax() {
    ll result = 0;
    do {
        vector<ll> tmp_num = num;
        vector<char> tmp_op = op;
        for (int i = 1; i <= 3; i++) { //1순위 연산자부터 3순위 연산자까지 계산
            char cur_op = nowOp(i); //i순위 연산자는?
            for (int i = 0; i < tmp_op.size(); i++) {
                if (cur_op == tmp_op[i]) { //이번에 계산해야할 연산자면
                    int idx = i; //위치 저장
                    ll res = calc(tmp_num[idx], tmp_num[idx + 1], cur_op); //계산
                    tmp_num.erase(tmp_num.begin() + idx + 1);
                    tmp_num[idx] = res;
                    tmp_op.erase(tmp_op.begin() + idx);
                    i--; //인덱스를 건너뛰지 않도록
                }
            }
        }
        result = max(result, abs(tmp_num[0])); //최댓값 갱신
    } while (next_permutation(op_pri, op_pri + 3)); //{1, 2, 3}부터 {3, 2, 1}까지
    return result;
}

ll solution(string expression) {
    string tmp;
    for (int i = 0; i < expression.size(); i++) { //연산자와 피연산자를 나누어 num, op 벡터에 넣기
        if ((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*')) {
            num.push_back(stol(tmp));
            tmp.clear();
            op.push_back(expression[i]);
        } else
            tmp += expression[i];
    }
    num.push_back(stol(tmp));
    ll answer = findMax();
    num.clear();
    op.clear();
    return answer;
}

int main() {
    cout << solution("100-200*300-500+20") << '\n';
    cout << solution("50*6-3*2") << '\n';
}