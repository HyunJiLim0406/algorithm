#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree, building;

vector<int> topology(int num) {
    vector<int> result(num + 1, 0);
    queue<int> q;
    for (int i = 1; i <= num; i++) { //초기 큐 입력
        if (indegree[i] == 0) { //부모 정점이 없으면 큐에 삽입
            result[i] = building[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); //현재 빌딩
        int cost = result[cur]; //현재 빌딩을 건설하기까지 걸린 총 시간
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int node = graph[cur][i]; //연결된 건물
            indegree[node]--;
            result[node] = max(result[node], cost + building[node]); //건설에 걸리는 총 시간 갱신
            if (indegree[node] == 0) //더이상 부모 정점이 없으면 큐에 삽입
                q.push(node);
        }
    }
    return result;
}

int main() {
    int N, p;

    cin >> N;
    graph.assign(N + 1, vector<int>(0));
    indegree.assign(N + 1, 0);
    building.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> building[i];
        while (true) {
            cin >> p;
            if (p == -1)
                break;
            graph[p].push_back(i); //연결관계 삽입
            indegree[i]++; //부모 정점의 수 증가
        }
    }
    vector<int> result = topology(N);
    for (int i = 1; i <= N; i++)
        cout << result[i] << '\n';
}