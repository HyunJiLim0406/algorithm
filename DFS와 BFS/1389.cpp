#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int bfs(int start) {
    int dist = 0; //start의 케빈 베이컨 수
    queue<int> q;
    vector<int> visited;
    visited.assign(graph.size() + 1, -1);

    visited[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == -1) { //미방문 정점
                visited[graph[cur][i]] = visited[cur] + 1; //방문 처리
                dist += visited[graph[cur][i]]; //케빈 베이컨 수 증가
                q.push(graph[cur][i]);
            }
        }
    }
    return dist;
}

int main() {
    int N, M, A, B;

    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0));
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int min_bacon = 1e9, result;
    for (int i = 1; i <= N; i++) {
        int bacon = bfs(i);
        if (min_bacon > bacon) { //최솟값 갱신
            min_bacon = bacon;
            result = i;
        }
    }
    cout << result;
}