#include <iostream>
#include <vector>

using namespace std;
const int INF = 10001;

int main() {
    vector<vector<int>> dp; //i번째 까지의 동전으로 j원을 만드는 최소 개수
    vector<int> coin;
    int n, k;

    cin >> n >> k;
    dp.assign(n, vector<int>(k + 1, INF));
    coin.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 0; i <= k; i += coin[0]) //초기화
        dp[0][i] = i / coin[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < coin[i]) //coin[i]가 j보다 큰 수일 때(coin[i]로 j원을 만들 수 없음)
                dp[i][j] = dp[i - 1][j];
            else //dp[i][j-coin[i]]에서 동전을 하나 추가한 것과, dp[i-1][j]와 INF을 비교
                dp[i][j] = min(INF, min(dp[i - 1][j], dp[i][j - coin[i]] + 1));
        }
    }
    cout << ((dp[n - 1][k] == INF) ? -1 : dp[n - 1][k]); //INF이면 불가능
}