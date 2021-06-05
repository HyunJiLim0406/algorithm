#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int pickCandy(int N, int M) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            dp[i][j] += max(dp[i][j - 1], dp[i - 1][j]); //대각선 고려하지 않아도 괜찮음
    }
    return dp[N][M];
}

int main() {
    int N, M;

    cin >> N >> M;
    dp.assign(N+1, vector<int>(M+1)); //위, 왼쪽 한줄씩 추가
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> dp[i][j];
    }
    cout<<pickCandy(N, M);
}