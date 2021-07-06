#include <iostream>

using namespace std;

long long dp[91][2];

long long dpBinary(int n) {
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; //0으로 끝나는 이친수
        dp[i][1] = dp[i - 1][0]; //1로 끝나는 이친수
    }
    return dp[n][0] + dp[n][1];
}

int main() {
    int N;

    cin >> N;
    cout<<dpBinary(N);
}