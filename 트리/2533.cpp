#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph, children, dp;

void dfs(int cur, int before) { //단방향 그래프로 변경
    for (int i = 0; i < graph[cur].size(); i++) {
        if (graph[cur][i] != before) { //자식들에 대해
            children[cur].push_back(graph[cur][i]);
            dfs(graph[cur][i], cur);
        }
    }
}

int fillDp(int cur, bool is_adapter) {
    if (dp[is_adapter][cur] == -1) { //미방문
        dp[is_adapter][cur] = 0; //초기화
        if (is_adapter) { //본인이 얼리아답터라면
            for (int i = 0; i < children[cur].size(); i++) //자식은
                dp[is_adapter][cur] += min(fillDp(children[cur][i], true), //얼리아답터여도 되고
                                           fillDp(children[cur][i], false)); //얼리아답터가 아니어도 됨
            dp[is_adapter][cur]++; //본인
        } else { //본인이 얼리아답터가 아니라면
            for (int i = 0; i < children[cur].size(); i++) //자식은
                dp[is_adapter][cur] += fillDp(children[cur][i], true); //얼리아답터여야 함
        }
    }
    return dp[is_adapter][cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, u, v;

    cin >> N;
    graph.assign(N + 1, vector<int>(0));
    children.assign(N + 1, vector<int>(0));
    dp.assign(2, vector<int>(N + 1, -1));
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0); //1을 root로 하는 트리 생성
    cout << min(fillDp(1, true), fillDp(1, false)); //root가 얼리아답터이거나 아니거나
}