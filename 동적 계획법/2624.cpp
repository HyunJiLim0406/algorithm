#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<pair<int, int>> coin;

int posSum(int idx, int amount) { //5원이 3개 있고 20원을 만든다면, 이전 단계에서 20원, 15원, 10원, 5원을 만든 경우를 더함
    int value = coin[idx].first, cnt = coin[idx].second + 1, result = 0;
    while (cnt--) {
        if (amount < 0) //0보다 작아지면 break
            break;
        result += dp[idx - 1][amount];
        amount -= value; //만들어야 하는 금액을 줄여나감
    }
    return result;
}

int fillDp(int T, int k) {
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= T; j++)
            dp[i][j] = posSum(i, j);
    }
    return dp[k][T];
}

int main() {
    int T, k;

    cin >> T >> k;
    dp.assign(k + 1, vector<int>(T + 1, 0));
    coin.assign(k + 1, make_pair(0, 0));
    for (int i = 1; i <= k; i++)
        cin >> coin[i].first >> coin[i].second;
    cout << fillDp(T, k);
}