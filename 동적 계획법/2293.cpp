#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> dp;
    vector<int> coin;
    int n, k;

    cin >> n >> k;
    dp.assign(k + 1, 0);
    coin.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 0; i <= k; i += coin[0]) //초기화
        dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= coin[i]) //dp[j-coin[i]]에서 동전을 하나 추가한 경우
                dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
}