#include <iostream>

using namespace std;

const int DIVISOR = 9901;
int dp[100001][3];

int main() {
    int N;

    cin >> N;
    dp[1][0] = dp[1][1] = dp[1][2] = 1; //초기값
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIVISOR; //사자가 없다면 이전 행 어디에 사자가 있어도 괜찮음
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIVISOR; //사자가 왼쪽에 있다면 이전 행에 사자가 없거나 오른쪽에 있거나
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % DIVISOR; //사자가 오른쪽에 있다면 이전 행에 사자가 없거나 왼쪽에 있거나
    }
    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % DIVISOR;
}