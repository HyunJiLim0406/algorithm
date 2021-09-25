#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> dp;

ll fillDp(int n) {
    dp[0] = 1; //초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) //점화식
            dp[i] += dp[j] * dp[i - 1 - j];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1, 0);

    cout << fillDp(n);
}