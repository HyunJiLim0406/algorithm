#include <iostream>
#include <vector>

using namespace std;

vector<int> graph, visited, result;

void dfs(int start, int cur) {
    if (visited[cur] == start) { //이미 방문함
        if (cur == start) //시작점으로 돌아옴
            result.push_back(start);
        return;
    }
    visited[cur] = start; //방문 처리
    dfs(start, graph[cur]);
}

int main() {
    int N;

    cin >> N;
    graph.assign(N + 1, 0);
    visited.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> graph[i];
    for (int i = 1; i <= N; i++) //모든 정점에 대해 dfs 돌며 사이클 존재 확인
        dfs(i, i);
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
}