#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool isExist;

void dfs(int cur, int num) {
    if (num == 5) { //친구 5명을 찾음
        cout << 1;
        isExist = true;
        return;
    }
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]] && !isExist) {
            visited[graph[cur][i]] = true; //visited 처리
            dfs(graph[cur][i], num + 1);
            visited[graph[cur][i]] = false; //unvisited 처리
        }
    }
}

int main() {
    int N, M, first, second;

    cin >> N >> M;
    graph.assign(N, vector<int>(0));
    visited.assign(N, false);
    for (int i = 0; i < M; i++) { //리스트 형태로 저장
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    for (int i = 0; i < N; i++) { //i를 시작점으로
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }
    if (!isExist) //친구 관계 못찾음
        cout << 0;
}