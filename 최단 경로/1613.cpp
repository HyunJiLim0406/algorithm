#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> dp;

void floydWarshall(int n) { //플로이드 워셜
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dp[j][i] && dp[i][k])
                    dp[j][k] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, a, b;

    cin >> n >> k;
    dp.assign(n + 1, vector<bool>(n + 1));
    while (k--) {
        cin >> a >> b;
        dp[a][b] = true;
    }
    floydWarshall(n);
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (dp[a][b]) //먼저 일어남
            cout << -1;
        else if (dp[b][a]) //나중에 일어남
            cout << 1;
        else //알 수 없음
            cout << 0;
        cout << '\n';
    }
}