#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<pair<int, int>> app;

int fillDp(int N, int M, int tot_cost) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= tot_cost; j++) {
            dp[i][j] = dp[i - 1][j];
            if (app[i - 1].second <= j) //j의 비용으로 해당 앱을 지울 수 있다면
                dp[i][j] = max(dp[i][j], dp[i - 1][j - app[i - 1].second] + app[i - 1].first);
        }
    }
    for (int i = 0; i <= tot_cost; i++) { //M을 넘는 가장 작은 값
        if (dp[N][i] >= M)
            return i;
    }
    return -1;
}

int main() {
    int N, M, tot_cost = 0;

    cin >> N >> M;
    app.assign(N, make_pair(0, 0));
    for (int i = 0; i < N; i++)
        cin >> app[i].first;
    for (int i = 0; i < N; i++) {
        cin >> app[i].second;
        tot_cost += app[i].second; //모든 앱을 지우는 비용
    }
    dp.assign(N + 1, vector<int>(tot_cost + 1, 0));
    cout << fillDp(N, M, tot_cost);
}