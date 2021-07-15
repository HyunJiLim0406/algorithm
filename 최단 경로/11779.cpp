#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pp;

vector<vector<pp>> graph; //연결 정보
vector<pp> min_dist; //최단거리, 이전 정점

void dijkstra(int start, int end) {
    priority_queue<pp, vector<pp>, greater<pp>> pq; //min-heap
    min_dist[start] = make_pair(0, -1); //초기 입력
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cur_dist = pq.top().first; //시작점부터 현재 정점까지의 거리
        int cur = pq.top().second; //현재 정점
        pq.pop();

        if (cur == end)
            return;
        for (int i = 0; i < graph[cur].size(); i++) {
            int new_dist = cur_dist + graph[cur][i].second; //새로운 거리
            if (new_dist < min_dist[graph[cur][i].first].first) { //최단 경로 갱신 가능하면
                min_dist[graph[cur][i].first] = make_pair(new_dist, cur);
                pq.push(make_pair(new_dist, graph[cur][i].first));
            }
        }
    }
}

int main() {
    int n, m, s, d, w;
    stack<int> route;

    cin >> n >> m;
    graph.assign(n + 1, vector<pp>(0));
    min_dist.assign(n + 1, make_pair(INF, -1));
    for (int i = 0; i < m; i++) {
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
    }
    cin >> s >> d;
    dijkstra(s, d); //s를 시작점으로 다익스트라

    int p = d; //이전 정점으로 거슬러 올라가기
    while (true) {
        if (p == -1)
            break;
        route.push(p);
        p = min_dist[p].second;
    }
    cout << min_dist[d].first << '\n' << route.size() << '\n';
    while (!route.empty()) {
        cout << route.top() << ' ';
        route.pop();
    }
}