#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> input;
vector<vector<int>> dp;

int fillDp(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = dp[i - 1][j];
            if (input[i].first < j) //인사를 안하거나, 인사를 하거나
                dp[i][j] = max(dp[i][j], dp[i - 1][j - input[i].first] + input[i].second);
        }
    }
    return dp[N][100];
}

int main() {
    int N;

    cin >> N;
    input.assign(N + 1, make_pair(0, 0));
    dp.assign(N + 1, vector<int>(101, 0));
    for (int i = 1; i <= N; i++)
        cin >> input[i].first;
    for (int i = 1; i <= N; i++)
        cin >> input[i].second;
    cout << fillDp(N);
}