#include <iostream>

using namespace std;

const int DIVISOR = 10007;

int dp[1001];

int fillSquare(int n) { //점화식 세워보니까 그냥 피보나치 수열
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIVISOR;
    return dp[n];
}

int main() {
    int n;

    cin >> n;
    cout << fillSquare(n);
}