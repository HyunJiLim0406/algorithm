#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int DIVISOR = 1000000;

vector<int> dp;

int fillDp(string str) {
    if (str[0] - '0' == 0) //0으로 시작함
        return 0;
    dp[0] = dp[1] = 1; //초기화
    for (int i = 1; i < str.size(); i++) {
        int before_num = str[i - 1] - '0'; //이전 숫자
        int num = str[i] - '0'; //이번 숫자
        if (num != 0) //이번 숫자가 0이 아니라면 한자리로 쓸 수 있음
            dp[i + 1] += dp[i];
        if (before_num == 1 || (before_num == 2 && num <= 6)) { //두자리로 쓸 수 있는지 확인
            dp[i + 1] += dp[i - 1];
            dp[i + 1] %= DIVISOR;
        }
        if (dp[i + 1] == 0) //여전히 0이면 만들 수 있는 암호가 없는 것
            return 0;
    }
    return dp[str.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    cin >> str;
    dp.assign(str.size() + 1, 0);
    cout << fillDp(str);
}