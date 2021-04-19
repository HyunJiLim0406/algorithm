#include <iostream>

using namespace std;

const int DIVISOR = 1000000009;
long long dp[1000001];

void dpSum() { //dp[i-1]+1, dp[i-2]+2, dp[i-3]+3
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIVISOR;
}

int main() {
    int T, n;

    dpSum();
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout<<dp[n]<<'\n';
    }
}