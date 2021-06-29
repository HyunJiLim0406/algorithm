#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> dp(10001);

string calc(string num1, string num2) {
    stack<char> s;
    bool is_carry = false; //올림
    int i1 = num1.size() - 1, i2 = num2.size() - 1;
    while (i1 >= 0) { //num1의 길이만큼
        int n1 = num1[i1] - '0';
        int n2 = (i2 >= 0) ? num2[i2] - '0' : 0; //num2의 길이 넘었다면 0으로 초기화
        int num = n1 + n2;
        if (is_carry) //올림이 있었으면
            num++;
        if (num >= 10) { //10을 넘으면
            is_carry = true;
            num -= 10;
        } else //10을 넘지 않으면
            is_carry = false;
        s.push(num + '0'); //스택에 넣기
        i1--; i2--; //인덱스 조절
    }
    string result = (is_carry) ? "1" : ""; //result 초기화
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

string fillDp(int n) {
    dp[0] = "0"; dp[1] = "1"; //초기화
    for (int i = 2; i <= n; i++)
        dp[i] = calc(dp[i - 1], dp[i - 2]);
    return dp[n];
}

int main() {
    int N;

    cin >> N;
    cout << fillDp(N);
}