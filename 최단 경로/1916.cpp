#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pp;
const int INF = 1e9;

vector<vector<pp>> graph; //그래프 정보
vector<int> min_dist; //최단 경로

void dijkstra(int start) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    min_dist[start] = 0; //시작점의 최단 경로 초기화
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cur_dist = pq.top().first; //시작점부터 현재 정점까지의 거리
        int cur = pq.top().second; //현재 정점
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int new_dist = cur_dist + graph[cur][i].second; //cur을 거친 거리
            if (new_dist < min_dist[graph[cur][i].first]) { //이게 최단 경로일 수 있다면 갱신
                min_dist[graph[cur][i].first] = new_dist;
                pq.push(make_pair(new_dist, graph[cur][i].first));
            }
        }
    }
}

int main() {
    int N, M, s, d, w;

    cin >> N >> M;
    graph.assign(N + 1, vector<pp>(0));
    min_dist.assign(N + 1, INF);
    for (int i = 0; i < M; i++) {
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
    }
    cin >> s >> d;
    dijkstra(s); //시작점에 대한 다익스트라
    cout << min_dist[d];
}