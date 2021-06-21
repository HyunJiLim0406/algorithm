#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int bfs(int start, int n) {
    int cnt = 0;
    vector<int> dist(n + 1, 3);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (dist[cur] == 2) //더이상 탐색할 필요 없음
            continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (dist[graph[cur][i]] == 3) { //미방문 정점
                dist[graph[cur][i]] = dist[cur] + 1;
                q.push(graph[cur][i]);
                cnt++; //초대할 수 있는 친구 수 증가
            }
        }
    }
    return cnt;
}

int main() {
    int n, m, a, b;

    cin >> n >> m;
    graph.assign(n + 1, vector<int>(0));
    while (m--) { //양방향 그래프
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << bfs(1, n);
}