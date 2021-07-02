#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr, indegree;
vector<vector<int>> graph;

int topology(int N) {
    vector<int> cost(N + 1);
    queue<int> q;
    for (int i = 1; i <= N; i++) { //초기 큐 입력
        if (indegree[i] == 0) { //부모 정점이 없으면 큐에 삽입
            cost[i] = arr[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int node = graph[cur][i]; //연결된 정점
            cost[node] = max(cost[node], cost[cur] + arr[node]);
            indegree[node]--; //작업에 걸리는 총 시간 갱신
            if (indegree[node] == 0) //더이상 부모 정점이 없으면 큐에 삽입
                q.push(node);
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i++) //제일 오래걸린 작업
        result = max(result, cost[i]);
    return result;
}

int main() {
    int N, num, input;

    cin >> N;
    arr.assign(N + 1, 0);
    indegree.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>(0));
    for (int i = 1; i <= N; i++) {
        cin >> arr[i] >> num;
        while (num--) {
            cin >> input;
            graph[input].push_back(i); //연결관계 삽입
            indegree[i]++; //부모 정점의 수 증가
        }
    }
    cout << topology(N);
}