#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;
const int INF = 1e9;

vector<vector<tp>> graph;
vector<vector<int>> dp; //dp[i][j] = j의 비용으로 갈 수 있는 1->i의 최단거리

int dijkstra(int start, int end, int M) {
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    for (int i = 0; i <= M; i++) //나 자신까지의 거리는 비용에 상관없이 0
        dp[start][i] = 0;
    pq.push(make_tuple(0, 0, start));
    while (!pq.empty()) {
        int cur_dist = get<0>(pq.top()); //현재 정점까지의 거리
        int cur_cost = get<1>(pq.top()); //현재 정점까지의 비용
        int cur = get<2>(pq.top()); //현재 정점
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int dest = get<0>(graph[cur][i]); //목적지
            int new_dist = cur_dist + get<2>(graph[cur][i]); //start 정점에서 목적지까지의 거리
            int new_cost = cur_cost + get<1>(graph[cur][i]); //start 정점에서 목적지까지의 비용

            if ((new_cost <= M) && (dp[dest][new_cost] > new_dist)) { //비용이 M 이하이고, 기존의 최단거리보다 짧다면
                int tmp = new_cost;
                while (tmp <= M) { //갱신할 수 있는 곳까지 갱신
                    if (dp[dest][tmp] > new_dist)
                        dp[dest][tmp] = new_dist;
                    tmp++;
                }
                pq.push(make_tuple(new_dist, new_cost, dest)); //우선순위 큐에 삽입
            }
        }
    }
    return dp[end][M]; //M의 비용으로 갈 수 있는 1->end의 최단거리
}

int main() {
    int T, N, M, K, u, v, c, d;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        graph.assign(N + 1, vector<tp>(0));
        dp.assign(N + 1, vector<int>(M + 1, INF)); //NxM
        for (int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            graph[u].push_back(make_tuple(v, c, d));
        }
        int result = dijkstra(1, N, M);
        if (result == INF)
            cout << "Poor KCM\n";
        else
            cout << result << '\n';
    }
}