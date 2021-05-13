#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

void topology() { //위상정렬
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) { //초기입력
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' '; //출력
        for (int i = 0; i < graph[cur].size(); i++) {
            int connect = graph[cur][i];
            indegree[connect]--;
            if (indegree[connect] == 0) //방문해야 할 부모노드가 더이상 없으면
                q.push(connect);
        }
    }
}

int main() {
    int N, M, A, B;

    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0));
    indegree.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }
    topology();
}