#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> status;
vector<bool> cycle;
int isCycle;

void dfs(int start, int cur, int source) { //시작 정점, 현재 정점, 직전 정점
    if (status[cur]) { //이미 방문한 정점을 갔는데
        if (cur == start) //시작 정점이면 사이클
            isCycle = 1;
        else
            isCycle = 2; //사이클이 아님
        return;
    }
    status[cur] = 1; //방문 처리
    for (int i = 0; i < graph[cur].size() && !isCycle; i++) {
        if (graph[cur][i] != source) { //직전 정점이 아니면 연결된 정점 탐색
            dfs(start, graph[cur][i], cur);
        }
    }
}

int bfs(int start) {
    queue<int> q;

    status[start] = 1;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); //현재 정점
        q.pop();
        if (cycle[cur]) //사이클인 정점을 만나면 리턴
            return status[cur] - 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!status[graph[cur][i]]) { //미방문 정점
                status[graph[cur][i]] = status[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, first, second;

    cin >> N;
    graph.assign(N + 1, vector<int>(0));
    cycle.assign(N + 1, false);
    for (int i = 0; i < N; i++) {
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for (int i = 1; i <= N; i++) { //모든 정점에 대해 사이클에 포함된 정점이 맞는지 체크
        status.assign(N + 1, 0);
        isCycle = 0;
        dfs(i, i, -1);
        if (isCycle==1)
            cycle[i] = true;
    }

    for (int i = 1; i <= N; i++) { //모든 정점에 대해 사이클이면 0 출력, 아니면 bfs
        if (cycle[i])
            cout << 0 << ' ';
        else {
            status.assign(N + 1, 0);
            cout << bfs(i) << ' ';
        }
    }
}