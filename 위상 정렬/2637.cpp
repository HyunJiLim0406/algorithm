#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> topology(int n, vector<int> indegree, vector<vector<ci>> &graph) {
    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0)); //dp 배열
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //기본 부품
            result[i][i]++;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int cnt = graph[node][i].second;
            indegree[next_node]--;
            for (int j = 1; j <= n; j++) //필요한 기본 부품 수 더하기
                result[next_node][j] += (cnt * result[node][j]);
            if (!indegree[next_node]) //필요한 부품을 모두 구했으면
                q.push(next_node);
        }
    }
    return result[n];
}

int main() {
    int n, m, x, y, k;

    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while (m--) {
        cin >> x >> y >> k;
        indegree[x]++;
        graph[y].emplace_back(x, k);
    }

    vector<int> ans = topology(n, indegree, graph);
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //기본 부품만 출력
            cout << i << ' ' << ans[i] << '\n';
    }
}