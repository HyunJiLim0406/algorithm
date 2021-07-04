#include <iostream>
#include <stack>
#include <string>

using namespace std;

void hanoi(int from, int tmp, int to, int n) {
    if (n == 0) //종료조건
        return;
    hanoi(from, to, tmp, n - 1);
    cout << from << ' ' << to << '\n';
    hanoi(tmp, from, to, n - 1);
}

string plusNum(string num) {
    stack<char> s;
    bool is_carry = false;
    string result = "";
    for (int i = num.size() - 1; i >= 0; i--) {
        int tmp = (num[i] - '0') * 2; //각 자리 덧셈
        if (is_carry) //올림 있었으면
            tmp++;
        if (tmp >= 10) { //10 이상이면
            is_carry = true;
            tmp -= 10;
        } else //10 미만이면
            is_carry = false;
        s.push(tmp + '0');
    }
    if (is_carry) //올림 있었으면
        s.push('1');
    while (!s.empty()) { //결과
        result += s.top();
        s.pop();
    }
    return result;
}

string calc(int num) {
    if (num == 0) //종료조건
        return "1";
    string tmp = calc(num - 1); //재귀 호출
    return plusNum(tmp); //같은 수 더하기
}

int main() {
    int N;

    cin >> N;
    string result = calc(N);
    result[result.size() - 1]--; //1 빼줌
    cout << result << '\n';
    if (N <= 20)
        hanoi(1, 2, 3, N);
}