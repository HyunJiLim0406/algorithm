#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

vector<int> topology(int N) {
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= N; i++) { //초기 큐 입력
        if (indegree[i] == 0) //부모 정점이 없으면 큐에 삽입
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            int node = graph[cur][i]; //연결된 정점
            indegree[node]--;
            if (indegree[node] == 0) //더이상 부모 정점이 없으면 큐에 삽입
                q.push(node);
        }
    }
    if (result.size() == N) //순서를 정함
        return result;
    return {0}; //순서를 정하는게 불가능함
}

int main() {
    int N, M, num;

    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0));
    indegree.assign(N + 1, 0);
    while (M--) {
        cin >> num;
        vector<int> tmp(num);
        for (int i = 0; i < num; i++)
            cin >> tmp[i];
        for (int i = 0; i < num - 1; i++) {
            graph[tmp[i]].push_back(tmp[i + 1]); //연결관계 삽입
            indegree[tmp[i + 1]]++; //부모 정점의 수 증가
        }
    }
    vector<int> result = topology(N);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
}