#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> hack, visited;

int dfs(int cur, int idx) {
    int node = 1;
    visited[cur] = idx;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (visited[graph[cur][i]] < idx) //미방문 정점
            node += dfs(graph[cur][i], idx);
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, A, B;

    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0));
    hack.assign(N + 1, -1);
    visited.assign(N + 1, 0);
    while (M--) {
        cin >> A >> B;
        graph[B].push_back(A);
    }
    int max_hack = -1;
    for (int i = 1; i <= N; i++) {
        hack[i] = dfs(i, i);
        max_hack = max(max_hack, hack[i]); //최댓값 갱신
    }
    for (int i = 1; i <= N; i++) { //출력
        if (hack[i] == max_hack)
            cout << i << ' ';
    }
}