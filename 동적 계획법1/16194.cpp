#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int cost[1001];

int dpMin(int n) {
    dp[1] = cost[1];
    for (int i = 2; i <= n; i++) {
        int result = cost[i];
        for (int j = 1; j <= (i / 2); j++) //범위를 여기까지만 해도 될 것 같은데?
            result = min(result, cost[j] + dp[i - j]); //j개의 카드가 들어있는 팩 1개, 나머지 카드 i-j개를 사는 최솟값
        dp[i] = result;
    }
    return dp[n];
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    cout << dpMin(N);
}