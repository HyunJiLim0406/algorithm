#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree, time_cost, max_time;

int topology(int target) {
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) { //초기 큐 입력
        if (indegree[i] == 0) { //부모 정점이 없으면 큐에 삽입
            max_time[i] = time_cost[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); //현재 빌딩
        int cost = max_time[cur]; //현재 빌딩을 건설하기까지 걸린 총 시간
        q.pop();

        if (cur == target) //목표 빌딩이라면 리턴
            return cost;
        for (int i = 0; i < graph[cur].size(); i++) {
            int connect = graph[cur][i]; //연결된 건물
            indegree[connect]--;
            max_time[connect] = max(max_time[connect], cost + time_cost[connect]); //건설에 걸리는 총 시간 갱신
            if (indegree[connect] == 0) //더이상 부모 정점이 없으면 큐에 삽입
                q.push(connect);
        }
    }
    return -1;
}

int main() {
    int T, N, K, X, Y, W;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        graph.assign(N + 1, vector<int>(0)); //연결관계 그래프
        indegree.assign(N + 1, 0); //각 정점의 부모 정점 수
        time_cost.assign(N + 1, 0); //각 빌딩의 건설 시간
        max_time.assign(N + 1, 0); //각 빌딩을 건설하는데 걸리는 총 시간
        for (int i = 1; i <= N; i++)
            cin >> time_cost[i];
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            graph[X].push_back(Y); //연결관계 삽입
            indegree[Y]++; //부모 정점의 수 증가
        }
        cin >> W; //목표 빌딩
        cout << topology(W) << '\n';
    }
}