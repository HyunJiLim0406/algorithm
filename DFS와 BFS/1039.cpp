#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(11, vector<int>(1e6 + 1, -1));

int dfs(string n, int cnt, int k) {
    int num = stoi(n);
    if (cnt == k)
        return num;
    if (dp[cnt][num] != -1)
        return dp[cnt][num];
    for (int i = 0; i < n.size(); i++) {
        for (int j = i + 1; j < n.size(); j++) {
            if (i == 0 && n[j] == '0')
                continue;
            swap(n[i], n[j]);
            dp[cnt][num] = max(dp[cnt][num], dfs(n, cnt + 1, k));
            swap(n[i], n[j]);
        }
    }
    return dp[cnt][num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    int k;

    cin >> n >> k;
    cout << dfs(n, 0, k);
}