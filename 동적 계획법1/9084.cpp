#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;
vector<vector<int>> dp;

int fillDp(int N, int M) {
    for (int i = 0; i <= M; i += coin[0]) //초기화
        dp[0][i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i - 1][j]; //이번 동전 쓰지 않음
            if (j >= coin[i]) //이번 동전 사용
                dp[i][j] += dp[i][j - coin[i]];
        }
    }
    return dp[N - 1][M];
}

int main() {
    int T, N, M;

    cin >> T;
    while (T--) {
        cin >> N;
        coin.assign(N, 0);
        for (int i = 0; i < N; i++)
            cin >> coin[i];
        cin >> M;
        dp.assign(N, vector<int>(M + 1));
        cout << fillDp(N, M) << '\n';
    }
}