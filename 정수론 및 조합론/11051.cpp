#include <iostream>
using namespace std;

int dp[1001][1001] = { 0, };

int binomial(int N, int K) {
    if (N / 2 < K)
        K = N - K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K && j <= i; j++) {
            if (j == 0 || j == i) //4C0, 4C4 같은 끄뜨머리
                dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; //오버플로우 방지
            }
        }
    }
    return dp[N][K];
}

int main() {
    int N, K;

    cin >> N >> K;
    cout << binomial(N, K);
}