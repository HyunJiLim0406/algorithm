#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

vector<int> topology() { //위상정렬
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = indegree.size();
    for (int i = 1; i < size; i++) { //초기입력
        if (indegree[i] == 0)
            pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        result.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];
            indegree[next_node]--;
            if (indegree[next_node] == 0) //방문해야 할 부모노드가 더이상 없으면
                pq.push(next_node);
        }
    }
    return result;
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
    vector<int> topology_sort = topology();
    for (int i = 0; i < topology_sort.size(); i++)
        cout << topology_sort[i] << ' ';
}