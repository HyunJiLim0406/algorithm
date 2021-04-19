#include <iostream>

using namespace std;

const int DIVISOR = 10007;
int dp[1001][10]; //i 자리의 오르막 수에서 숫자 j로 끝나는 수들

int dpStair(int n) {
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) //dp[2][1] = dp[1][0]+dp[1][1]
                dp[i][j] += dp[i - 1][k];
            dp[i][j] %= DIVISOR;
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++)
        result += dp[n][i];
    return result %= DIVISOR;
}

int main() {
    int N;

    cin >> N;
    cout << dpStair(N);
}