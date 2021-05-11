#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;
const int INF = 1e9;

vector<int> min_dist; //최단 거리
vector<int> result; //결과

void dijkstra(int start, vector<vector<pp>> graph) {
    priority_queue<pp, vector<pp>, greater<pp>> pq; //min-heap
    int size = graph.size();
    min_dist.assign(size, INF); //최단 거리 초기화

    min_dist[start] = 0; //시작점의 거리는 0
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cur_dist = pq.top().first; //시작점부터 cur 까지의 최단 거리
        int cur = pq.top().second; //현재 정점
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) { //연결된 정점에 대해
            int new_dist = cur_dist + graph[cur][i].second; //cur을 거쳐서 온 거리
            if (new_dist < min_dist[graph[cur][i].first]) { //이게 현재의 graph[cur][i]의 최단 거리보다 짧다면
                min_dist[graph[cur][i].first] = new_dist; //갱신
                pq.push(make_pair(new_dist, graph[cur][i].first)); //큐에 넣기
            }
        }
    }
}

int main() {
    int N, M, X, s, d, w, max_result = 0;
    vector<vector<pp>> graph; //입력 그래프
    vector<vector<pp>> r_graph; //역방향 그래프

    cin >> N >> M >> X;
    graph.assign(N + 1, vector<pp>(0));
    r_graph.assign(N + 1, vector<pp>(0));
    result.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
        r_graph[d].push_back(make_pair(s, w));
    }

    dijkstra(X, graph); //X에서 집으로 돌아감
    for (int i = 1; i <= N; i++)
        result[i] = min_dist[i];

    dijkstra(X, r_graph); //집에서 X로 감
    for (int i = 1; i <= N; i++) {
        result[i] += min_dist[i];
        max_result = max(max_result, result[i]); //최댓값 갱신
    }
    cout << max_result;
}