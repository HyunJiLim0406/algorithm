#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> graph;

set<int> bfs(int N, int start, int distance) {
    set<int> result;
    queue<int> q;
    vector<int> dist(N + 1, -1);
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (dist[cur] == distance) { //최단거리가 K라면
            result.insert(cur);
            continue;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            if (dist[graph[cur][i]] == -1) { //미방문 정점
                dist[graph[cur][i]] = dist[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    return result;
}

int main() {
    int N, M, K, X, a, b;

    cin >> N >> M >> K >> X;
    graph.assign(N + 1, vector<int>(0));
    while (M--) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    set<int> result = bfs(N, X, K);
    if (result.empty()) //도시가 하나도 존재하지 않으면
        cout << -1;
    else {
        for (auto s:result)
            cout << s << '\n';
    }
}