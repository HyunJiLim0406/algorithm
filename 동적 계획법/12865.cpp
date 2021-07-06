#include <iostream>
#include <algorithm>
using namespace std;

int W[101], V[101];
int dp[101][100001];

int knapsack(int N, int K) { //컴알 강의자료 참고함
    for (int i = 1; i <= N; i++) { //각 아이템에 대해
        for (int j = K; j >= 0; j--) { //모든 경우의 무게에 대해 계산해보는 것임
            if (W[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
        }
    }
    return dp[N][K];
}

int main() {
    int N, K;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
    cout << knapsack(N, K);
}