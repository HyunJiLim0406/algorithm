#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<ll>> dp(31, vector<ll>(31)); //dp[i][j] : i개의 온전한 알약과 j개의 쪼개진 알약을 먹는 경우의 수

void fillDp() { //30까지 미리 구해둠
    for (int i = 0; i < 31; i++)
        dp[0][i] = 1;
    for (int i = 1; i < 31; i++) {
        dp[i][0] = dp[i - 1][1]; //쪼개진 알약이 없을 때
        for (int j = 1; j < 31; j++) //온전한 알약을 쪼개거나, 쪼개진 알약을 먹거나
            dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
    }
}

int main() {
    int num;

    fillDp();
    while (true) {
        cin >> num;
        if (!num)
            break;
        cout << dp[num][0] << '\n';
    }
}