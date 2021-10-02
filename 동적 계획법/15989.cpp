#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10000;

vector<vector<int>> dp;

void fillDp() {
    dp.assign(MAX + 1, vector<int>(4, 0));
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for (int i = 4; i <= MAX; i++) { //경우의 수가 오름차순이 되도록
        dp[i][1] = dp[i - 1][1]; //1로 끝남
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2]; //2로 끝남
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]; //3으로 끝남
    }
}

int main() {
    int t, n;

    fillDp();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
}