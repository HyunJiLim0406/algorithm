#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1e9;
typedef pair<int, int> pp;

vector<vector<pp>> graph; //graph[i][j].first = dest, graph[i][j].second = weight
vector<int> V_dist; //INF로 초기화
vector<bool> visited; //방문 체크
priority_queue<pp, vector<pp>, greater<pp>> min_dist; //min-heap, min_dist.first = distance, min_dist.second = source

void dijkstra(int start) {
    int new_dist;

    V_dist[start] = 0; //시작점의 거리는 0
    min_dist.push(make_pair(V_dist[start], start)); //거리와 source 투입

    while (!min_dist.empty()) { //우선순위 큐가 비어있지 않을 때
        int dist = min_dist.top().first; //현재 노드 까지의 최단 거리
        int source = min_dist.top().second; //노드
        min_dist.pop();

        if (!visited[source]) { //방문한 적 없는 노드라면
            for (int i = 0; i < graph[source].size(); i++) { //해당 노드가 source인 모든 정점(dest)
                new_dist = dist + graph[source][i].second; //현재 노드까지의 최단거리 + source에서 dest까지의 weight
                if (new_dist < V_dist[graph[source][i].first]) { //이 값이 기존의 V_dist[dest]보다 작다면
                    V_dist[graph[source][i].first] = new_dist; //dest의 최단거리 갱신
                    min_dist.push(make_pair(new_dist, graph[source][i].first)); //우선순위 큐에 거리와 dest 노드 정보 삽입
                }
            }
        }
        visited[source] = true; //source 노드 방문 처리
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K, s, d, w;

    cin >> V >> E >> K;
    graph.assign(V + 1, vector<pp>(0));
    V_dist.assign(V + 1, INF);
    visited.assign(V + 1, false);
    for (int i = 0; i < E; i++) {
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (V_dist[i] == INF)
            cout << "INF\n";
        else
            cout << V_dist[i] << '\n';
    }
}