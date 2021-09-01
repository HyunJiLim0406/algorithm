#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<vector<pair<int, int>>> graph;

vector<pair<int, int>> dijkstraMST(int N) {
    vector<pair<int, int>> result;
    priority_queue<tp, vector<tp>, greater<>> pq;
    vector<int> min_dist(N + 1, 1e9);
    min_dist[1] = 0;
    pq.push(tp(min_dist[1], 1, 0));
    while (!pq.empty()) {
        int cost = get<0>(pq.top()); //비용
        int cur = get<1>(pq.top()); //현재 노드
        int parent = get<2>(pq.top()); //부모 노드
        pq.pop();

        if (cost != min_dist[cur]) //고려할 필요 없음
            continue;
        if (parent != 0) //슈퍼컴퓨터가 아니라면 연결정보 넣기
            result.emplace_back(cur, parent);
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            if (min_dist[next] > next_cost) { //최단 거리 갱신 가능
                min_dist[next] = next_cost;
                pq.push(tp(next_cost, next, cur));
            }
        }
    }
    return result;
}

int main() {
    int N, M, A, B, C;

    cin >> N >> M;
    graph.assign(N + 1, vector<pair<int, int>>(0));
    while (M--) { //양방향 그래프 연결
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
    }
    vector<pair<int, int>> result = dijkstraMST(N);
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << ' ' << result[i].second << '\n';
    }
}