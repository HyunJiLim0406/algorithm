#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<ll>> fillDp(int n, int max_dist, vector<int> &dist, vector<int> &repair_time) {
    vector<vector<ll>> dp(2, vector<ll>(n + 2, 0));
    dp[0][0] = 0; //dp
    dp[1][0] = -1; //경로 추적

    for (int i = 1; i <= n + 1; i++) {
        ll d = 0;
        dp[0][i] = 10e9;
        for (int j = i - 1; j >= 0; j--) {
            d += dist[j];
            if (d > max_dist) //너무 떨어져 있음
                break;
            if (repair_time[j] + dp[0][j] < dp[0][i]) { //경로 갱신
                dp[0][i] = repair_time[j] + dp[0][j];
                dp[1][i] = j;
            }
        }
    }
    return dp;
}

vector<ll> findRoute(int n, vector<vector<ll>> &dp) {
    vector<ll> ans;
    int cur = n + 1;
    while (dp[1][cur] != -1) { //-1을 만날 때까지 경로 입력
        ans.push_back(dp[1][cur]);
        cur = dp[1][cur];
    }
    return ans;
}

int main() {
    int max_dist, n;

    cin >> max_dist >> n;
    vector<int> dist(n + 1);
    vector<int> repair_time(n);
    repair_time.push_back(0);
    for (int i = 0; i < n + 1; i++)
        cin >> dist[i];
    for (int i = 1; i <= n; i++)
        cin >> repair_time[i];

    vector<vector<ll>> ans = fillDp(n, max_dist, dist, repair_time);
    cout << ans[0][n + 1] << '\n';

    vector<ll> route = findRoute(n, ans);
    cout << route.size() - 1 << '\n';
    for (int i = route.size() - 2; i >= 0; i--) //거꾸로 출력
        cout << route[i] << ' ';
}