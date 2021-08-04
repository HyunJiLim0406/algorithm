#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 3;

vector<vector<int>> dp;

void fillDp(int N, int K) {
    for (int i = 3; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j]; //이번 칸을 칠하지 않던가
            if (j > 0) //이번 칸을 칠하거나
                dp[i][j] += dp[i - 2][j - 1];
            dp[i][j] %= MOD;
        }
    }
}

int main() {
    int N, K, result = 0;

    cin >> N >> K;
    dp.assign(N + 1, vector<int>(K + 1, 0));
    dp[1][1] = dp[2][1] = 1; //첫번째 칸을 칠함
    fillDp(N, K);
    result += dp[N - 1][K];

    dp.assign(N + 1, vector<int>(K + 1, 0));
    dp[1][0] = dp[2][0] = dp[2][1] = 1; //첫번째 칸을 칠하지 않음
    fillDp(N, K);
    result += ((dp[N - 1][K] + dp[N - 2][K - 1]) % MOD);
    cout << result % MOD;
}