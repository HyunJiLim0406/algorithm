#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

vector<vector<pair<int, int>>> graph;

pair<int, int> dijkstra(int n, int start) {
    int cnt = 0, max_dist = 0;
    vector<int> min_dist(n + 1, INF); //초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    min_dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (min_dist[cur] < dist)
            continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            int node = graph[cur][i].first;
            int cost = graph[cur][i].second;
            if (min_dist[node] > dist + cost) { //최소경로 갱신
                min_dist[node] = dist + cost;
                pq.push(make_pair(min_dist[node], node));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (min_dist[i] != INF) { //감염된 컴퓨터 확인
            cnt++;
            max_dist = max(max_dist, min_dist[i]);
        }
    }
    return make_pair(cnt, max_dist);
}

int main() {
    int T, n, d, c, a, b, s;

    cin >> T;
    while (T--) {
        cin >> n >> d >> c;
        graph.assign(n + 1, vector<pair<int, int>>(0));
        while (d--) {
            cin >> a >> b >> s;
            graph[b].emplace_back(a, s);
        }
        pair<int, int> result = dijkstra(n, c);
        cout << result.first << ' ' << result.second << '\n';
    }
}