#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> node_dist;

int bfs(int start, int target) {
    queue<int> q;
    node_dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) //목표 정점
            break;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];
            if (node_dist[next_node] == -1) { //미방문 정점
                node_dist[next_node] = node_dist[cur] + 1;
                q.push(next_node);
            }
        }
    }
    return node_dist[target];
}

int main() {
    int n, s, t, m, x, y;

    cin >> n >> s >> t >> m;
    graph.assign(n + 1, vector<int>(0));
    node_dist.assign(n + 1, -1); //최단 거리 초기화
    while (m--) { //양방향 그래프
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << bfs(s, t);
}