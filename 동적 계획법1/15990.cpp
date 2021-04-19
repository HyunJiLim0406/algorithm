#include <iostream>

using namespace std;

const int DIVISOR = 1000000009;
long long dp[1000001][3];

void dpSum() { //dp[i-1]+1, dp[i-2]+2, dp[i-3]+3
    dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;

    for (int i = 4; i <= 1000000; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % DIVISOR;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % DIVISOR;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % DIVISOR;
    }
}

int main() {
    int T, n;

    dpSum();
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1] + dp[n][2]) % DIVISOR << '\n';
    }
}