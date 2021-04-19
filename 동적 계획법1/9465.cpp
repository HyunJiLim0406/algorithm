#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[2][100001];
vector<vector<int>> cost;

int dpSticker(int n) {
    dp[0][1] = cost[0][1];
    dp[1][1] = cost[1][1];

    for (int i = 2; i <= n; i++) { //붙여서 떼거나, 건너뛰고 떼거나
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + cost[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + cost[1][i];
    }
    return max(dp[0][n], dp[1][n]);
}

int main() {
    int T, n, input;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cost.assign(2, vector<int>(0));
        cost[0].push_back(0);
        cost[1].push_back(0);
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                cin >> input;
                cost[j].push_back(input);
            }
        }
        cout << dpSticker(n) << '\n';
        cost.clear();
    }
}