#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

bool bfs(int end) {
    vector<bool> visited(end + 1);
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) //목적지 도달
            return true;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visited[graph[cur][i]]) { //미방문 정점
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
    return false;
}

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        graph.assign(n + 2, vector<int>(0));
        vector<pair<int, int>> spot(n + 2);
        for (int i = 0; i < n + 2; i++)
            cin >> spot[i].first >> spot[i].second;
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                if (abs(spot[i].first - spot[j].first) + abs(spot[i].second - spot[j].second) <= 1000) { //양방향 그래프 생성
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        cout << (bfs(n + 1) ? "happy" : "sad")<<'\n';
    }
}