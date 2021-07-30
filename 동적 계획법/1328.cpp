#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MODULAR = 1e9 + 7;

int main() {
    int N, L, R;

    cin >> N >> L >> R;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(L + 1, vector<ll>(R + 1, 0)));
    dp[1][1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            for (int k = 1; k <= R; k++) //가장 작은 빌딩을 왼쪽, 오른쪽, 중간에 넣기
                dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % MODULAR;
        }
    }
    cout<<dp[N][L][R];
}