#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;
const int INF = 1e9 + 1;

int s, t;
vector<vector<pp>> graph;

bool isReachable(int weight) { //이 무게로 갈 수 있는지 확인
    queue<int> q;
    vector<bool> visited;
    visited.assign(graph.size(), false);

    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == t) //목표지점 도달
            return true;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visited[graph[cur][i].first] && (graph[cur][i].second >= weight)) { //지정 무게보다 튼튼한 다리로 연결된 미방문 정점
                visited[graph[cur][i].first] = true;
                q.push(graph[cur][i].first);
            }
        }
    }
    return false;
}

int upperSearch(int left, int right) { //upper-bound
    while (left <= right) {
        int mid = (left + right) / 2; //이번 중량
        if (!isReachable(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}

int main() {
    int N, M, A, B, C;
    int min_C = INF, max_C = 0;

    cin >> N >> M;
    graph.assign(N + 1, vector<pp>(0));
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
        min_C = min(min_C, C); //최소무게 갱신
        max_C = max(max_C, C); //최대무게 갱신
    }
    cin >> s >> t;
    cout << upperSearch(min_C, max_C);
}