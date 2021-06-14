#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int N;
vector<vector<int>> graph;
vector<vector<int>> dp;

int backtracking(int cur, int route) { //void로 하면 재갱신이 많아져서 시간 초과 발생
    if (route == (1 << N) - 1) { //모든 정점을 탐색했을 때
        if (graph[cur][0]) //돌아갈 수 있음
            return graph[cur][0];
        return INF;
    }
    if (dp[cur][route] != -1) //방문했었음
        return dp[cur][route];
    dp[cur][route] = INF; //초기화
    for (int i = 0; i < N; i++) {
        if ((route & (1 << i)) != 0 || !graph[cur][i]) //이미 갔던 곳이거나 길이 없을 때
            continue;
        int next_route = route | (1 << i); //다음 경로
        dp[cur][route] = min(dp[cur][route], graph[cur][i] + backtracking(i, next_route)); //최솟값 갱신
    }
    return dp[cur][route];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    graph.assign(N, vector<int>(N));
    dp.assign(N, vector<int>((1 << N), -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }
    cout << backtracking(0, 1);
}