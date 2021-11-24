#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

vector<int> topology(int n) {
    vector<int> ans(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) { //시작 정점 큐에 넣기
        if (!indegree[i]) {
            ans[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        int semester = ans[cur];
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];
            indegree[next_node]--;
            if (!indegree[next_node]) { //다음에 접근 가능한 정점
                ans[next_node] = semester + 1;
                q.push(next_node);
            }
        }
    }
    return ans;
}

int main() {
    int n, m, a, b;

    cin >> n >> m;
    graph.assign(n + 1, vector<int>(0));
    indegree.assign(n + 1, 0);
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    vector<int> ans = topology(n); //위상 정렬
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}