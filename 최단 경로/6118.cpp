#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> min_dist;
vector<vector<int>> graph;

void bfs(int start) { //bfs
    queue<int> q;
    min_dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        int dist = min_dist[cur];
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            if (min_dist[graph[cur][i]] == -1) {
                min_dist[graph[cur][i]] = dist + 1;
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() {
    int N, M, a, b;

    cin >> N >> M;
    min_dist.assign(N + 1, -1);
    graph.assign(N + 1, vector<int>(0));
    while (M--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    int idx = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (min_dist[i] > min_dist[idx]) { //최대 거리 갱신
            idx = i;
            cnt = 0;
        }
        if (min_dist[i] == min_dist[idx]) //최대 거리와 같은 거리의 정점
            cnt++;
    }
    cout << idx << ' ' << min_dist[idx] << ' ' << cnt;
}