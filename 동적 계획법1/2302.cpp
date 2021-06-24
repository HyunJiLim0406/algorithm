#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_vip;
vector<int> dp;

int fillDp(int N) {
    dp[0] = dp[1] = 1; //초기화
    for (int i = 2; i <= N; i++) {
        dp[i] += dp[i - 1]; //자기자리에 앉는 경우
        if (!is_vip[i] && !is_vip[i - 1]) //본인 또는 왼쪽 사람이 vip가 아니라면 바꿔서 앉을 수 있음
            dp[i] += dp[i - 2];
    }
    return dp[N];
}

int main() {
    int N, M, input;

    cin >> N >> M;
    is_vip.assign(N + 1, false);
    dp.assign(N + 1, 0);
    while (M--) {
        cin >> input;
        is_vip[input] = true;
    }
    cout << fillDp(N);
}