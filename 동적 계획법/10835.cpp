#include <iostream>
#include <vector>

using namespace std;

vector<int> l_card, r_card;
vector<vector<int>> dp;

int score(int N, int l_idx, int r_idx) {
    if (l_idx == N || r_idx == N) //어느 쪽 더미든 남은 카드가 없을 때
        return 0;
    if (dp[l_idx][r_idx] == -1) { //이 상태에서 연산한 적 없을 때
        if (l_card[l_idx] > r_card[r_idx]) //2번 규칙
            dp[l_idx][r_idx] = max(dp[l_idx][r_idx], score(N, l_idx, r_idx + 1) + r_card[r_idx]);
        dp[l_idx][r_idx] = max(dp[l_idx][r_idx], score(N, l_idx + 1, r_idx)); //1번 규칙 - 왼쪽 카드 버리기
        dp[l_idx][r_idx] = max(dp[l_idx][r_idx], score(N, l_idx + 1, r_idx + 1)); //1번 규칙 - 둘 다 버리기
    }
    return dp[l_idx][r_idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    l_card.assign(N, 0);
    r_card.assign(N, 0);
    dp.assign(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
        cin >> l_card[i];
    for (int i = 0; i < N; i++)
        cin >> r_card[i];
    cout << score(N, 0, 0);
}