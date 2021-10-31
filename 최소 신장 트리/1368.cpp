#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prim(int size, int start, vector<vector<int>> &graph) {
    vector<int> dist(size, 100001); //각 논까지의 비용
    vector<bool> visited(size, false); //논 체크 여부
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second; //현재 논
        pq.pop();

        visited[cur] = true; //방문처리
        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            if (graph[cur][i] < dist[i]) { //비용이 더 적다면
                dist[i] = graph[cur][i];
                pq.push({dist[i], i});
            }
        }
    }

    int tot_weight = 0;
    for (int i = 0; i < size; i++)
        tot_weight += dist[i];
    return tot_weight;
}

int main() {
    int n, w;

    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) { //수원과 논 사이의 비용
        cin >> w;
        graph[i][n] = graph[n][i] = w;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j]; //논들 사이의 비용
    }

    cout << prim(n + 1, n, graph); //수원에서 시작하는 프림 알고리즘
}