#include <iostream>
#include <vector>

using namespace std;
const int INF = 100000;

int N, P;
vector<int> dp;
vector<vector<int>> graph;

bool isFulfill(int state) { //활성화된 발전소의 개수 구하기
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i))
            cnt++;
    }
    return cnt >= P;
}

int fillDp(int state) {
    if (isFulfill(state)) //다른 발전소를 더 활성화할 필요 없음
        return 0;
    if (dp[state] != -1) //이미 확인한 상태
        return dp[state];
    dp[state] = INF; //초기화
    for (int i = 0; i < N; i++) { //이번 상태에 활성화된 발전소 찾기
        if ((state & (1 << i)) == 0)
            continue;
        for (int j = 0; j < N; j++) { //다음 상태에 활성화할 발전소 찾기
            if (state & (1 << j))
                continue;
            int next_state = state | (1 << j);
            dp[state] = min(dp[state], graph[i][j] + fillDp(next_state));
        }
    }
    return dp[state];
}

int main() {
    int state = 0;
    string init;

    cin >> N;
    dp.assign(1 << N, -1);
    graph.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }
    cin >> init >> P;
    for (int i = 0; i < N; i++) {
        if (init[i] == 'Y') //초기 상태
            state |= (1 << i);
    }
    int result = fillDp(state);
    cout << ((result == INF) ? -1 : result);
}