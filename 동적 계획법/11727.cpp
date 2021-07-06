#include <iostream>

using namespace std;

const int DIVISOR = 10007;

int dp[1001];

int fillSquare(int n) { //dp[i-2]에 대해 1x2 블럭 2개를 사용하거나 2x2 블럭 1개를 사용할 수 있음
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % DIVISOR;
    return dp[n];
}

int main() {
    int n;

    cin >> n;
    cout << fillSquare(n);
}