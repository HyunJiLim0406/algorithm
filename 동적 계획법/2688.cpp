#include <iostream>

using namespace std;
typedef long long ll;

ll dp[65][10];

void fillDp() {
    for (int i = 0; i < 10; i++) //초기화
        dp[1][i] = 1;
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j != 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
}

int main() {
    int T, n;

    cin >> T;
    fillDp(); //미리 다 구해놓기
    while (T--) {
        cin >> n;
        ll result = 0;
        for (int i = 0; i < 10; i++)
            result += dp[n][i];
        cout << result << '\n';
    }
}