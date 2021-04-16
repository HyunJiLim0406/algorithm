#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i]);
    }
}

int main() {
    int N, M, first, second, cnt = 0;

    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0));
    visited.assign(N + 1, false);
    for (int i = 0; i < M; i++) { //리스트 형태로 저장
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) { //방문 안한 노드에 대해
            cnt++;
            dfs(i); //이 노드를 시작점으로 한 모든 연결되는 노드 visited 처리
        }
    }
    cout << cnt;
}