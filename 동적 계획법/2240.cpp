#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<vector<int>> dp;

int fillDp(int T, int W) {
    for (int i = 1; i <= T; i++) { //0행 (이동하지 않음)
        dp[0][i] = dp[0][i - 1];
        if (tree[i] == 1) //1번 나무로 떨어진다면
            dp[0][i]++;
    }
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= T; j++) {
            if ((i % 2) + 1 != tree[j]) //현재 위치에 과일이 떨어지지 않을 때
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else //현재 위치에 과일이 떨어질 때
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] + 1);
        }
    }
    return dp[W][T];
}

int main() {
    int T, W;

    cin >> T >> W;
    dp.assign(W + 1, vector<int>(T + 1));
    tree.assign(T + 1, 0);
    for (int i = 1; i <= T; i++)
        cin >> tree[i];
    cout << fillDp(T, W);
}