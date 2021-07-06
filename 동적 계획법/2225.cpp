#include <iostream>

using namespace std;

const int DIVISOR = 1000000000;
long long dp[201][201];

int dpSeparate(int N, int K) {
    for (int i = 0; i <= N; i++) //K=1일 때
        dp[1][i] = 1;
    for (int i = 2; i <= K; i++) {
        dp[i][0] = 1; //i개의 숫자로 0을 나타내는 방법은 0을 i개 사용하는 방법 1개뿐
        for (int j = 1; j <= N; j++) //dp[i][j-1]에 dp[i-1][0]+...+dp[i-1][j-1]이 있음
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIVISOR;
    }
    return dp[K][N];
}

int main() {
    int N, K;

    cin >> N >> K;
    cout << dpSeparate(N, K);
}