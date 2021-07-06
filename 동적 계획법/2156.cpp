#include <iostream>
#include <algorithm>

using namespace std;

int grape[10001] = {0,};
int dp[10001] = {0,};

int max_grape(int num) {
    for (int i = 1; i <= num; i++) {
        if (i <= 2) { //2개면 그냥 더하면 됨
            for (int j = 1; j <= i; j++)
                dp[i] += grape[j];
        } else //직전 최대 vs 해당+직전+직전직전직전의 최대 vs 해당+직전직전의 최대
            dp[i] = max(dp[i - 1], max(grape[i] + grape[i - 1] + dp[i - 3], grape[i] + dp[i - 2]));
    }
    return dp[num];
}

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> grape[i];
    cout << max_grape(n) << '\n';
}