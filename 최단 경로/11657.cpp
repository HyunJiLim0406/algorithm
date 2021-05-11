#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
const int INF = 1e9;

vector<tuple<int, int, int>> edges; //간선 정보
vector<long long> min_dist; //min_dist가 갱신되던 중 underflow가 발생할 수 있으므로 long long

bool bellmanFord(int start) {
    int v = min_dist.size() - 1;

    min_dist[start] = 0;
    for (int i = 0; i < v; i++) {
        bool isChanged = false;
        for (int j = 0; j < edges.size(); j++) {
            int source = get<0>(edges[j]);
            int dest = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            if (min_dist[source] == INF) //닿을 수 없는 정점
                continue;
            long long new_dist = min_dist[source] + weight; //source를 거쳐 dest로 가는 경로
            if (new_dist < min_dist[dest]) {
                if (i == (v - 1)) //거리 갱신이 v번 째에 이루어졌다면 사이클 발생한 것
                    return true;
                min_dist[dest] = new_dist;
                isChanged = true; //거리 갱신 표시
            }
        }
        if (!isChanged) //갱신 없었다면 더 이상 탐색할 필요 없음
            return false;
    }
    return false;
}

int main() {
    int N, M, A, B, C;

    cin >> N >> M;
    min_dist.assign(N + 1, INF);
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.push_back(make_tuple(A, B, C));
    }
    if (bellmanFord(1)) //사이클이 발생함
        cout << -1;
    else { //사이클이 발생하지 않음
        for (int i = 2; i <= N; i++)
            cout << ((min_dist[i] == INF) ? -1 : min_dist[i]) << '\n';
    }
}