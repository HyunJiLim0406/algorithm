#include <iostream>
#include <vector>

using namespace std;

vector<int> train;
vector<vector<int>> dp;

int fillDp(int N, int K) {
    for (int i = K; i <= N; i++) {
        dp[i][0] = dp[i - 1][0]; //소형 기관차 사용하지 않음
        for (int j = 1; j <= 3; j++) //소형 기관차를 사용하지 않거나, 사용하거나
            dp[i][j] = max(dp[i - 1][j], dp[i - K][j - 1] + train[i] - train[i - K]);
    }
    return dp[N][3];
}

int main() {
    int N, K;

    cin >> N;
    train.assign(N + 1, 0);
    dp.assign(N + 1, vector<int>(4, 0));
    for (int i = 1; i <= N; i++) { //누적합
        cin >> train[i];
        train[i] += train[i - 1];
    }
    cin >> K;
    cout << fillDp(N, K);
}