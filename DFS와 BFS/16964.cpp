#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> route, visited, idx, result;

bool cmp(const int &i1, const int &i2) {
    if (idx[i1] < idx[i2])
        return true;
    else
        return false;
}

void dfs(int cur) { //dfs 실행하며 결과를 result 벡터에 담기
    visited[cur] = true;
    result.push_back(cur);
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i]);
    }
}

bool isDFS() { //result와 route 비교
    for (int i = 0; i < route.size(); i++) {
        if (route[i] != result[i])
            return false;
    }
    return true;
}

int main() {
    int N, first, second;

    cin >> N;
    graph.assign(N + 1, vector<int>(0));
    visited.assign(N + 1, 0);
    idx.assign(N + 1, 0);
    route.assign(N, 0);
    for (int i = 1; i < N; i++) {
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    for (int i = 0; i < N; i++) { //각 정점의 인덱스
        cin >> route[i];
        idx[route[i]] = i;
    }

    for (int i = 1; i <= N; i++) //idx 기준 오름차순 정렬
        sort(graph[i].begin(), graph[i].end(), cmp);

    dfs(1);
    cout << isDFS();
}