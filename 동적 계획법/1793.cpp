#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 251;

vector<string> dp;

string plusNum(string a, string b) { //큰 수 더하기
    stack<char> s;
    string result;
    int idx1 = a.size() - 1, idx2 = b.size() - 1;
    bool carry = false;

    while (idx1 >= 0 && idx2 >= 0) {
        int num1 = a[idx1] - '0';
        int num2 = b[idx2] - '0';
        int sum = num1 + num2 + carry;

        carry = sum / 10;
        sum %= 10;
        s.push(sum + '0');
        idx1--;
        idx2--;
    }
    while (idx1 >= 0) {
        int sum = (a[idx1] - '0') + carry;
        carry = sum / 10;
        sum %= 10;
        s.push(sum + '0');
        idx1--;
    }
    while (idx2 >= 0) {
        int sum = (a[idx2] - '0') + carry;
        carry = sum / 10;
        sum %= 10;
        s.push(sum + '0');
        idx2--;
    }
    if (carry)
        s.push('1');
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

void fillDp() {
    dp.assign(SIZE, "");
    dp[0] = dp[1] = "1";
    for (int i = 2; i < SIZE; i++) //점화식
        dp[i] = plusNum(dp[i - 1], plusNum(dp[i - 2], dp[i - 2]));
}

int main() {
    int n;

    fillDp();

    while (cin >> n)
        cout << dp[n] << '\n';
}