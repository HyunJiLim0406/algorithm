#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
const int INF = 1e9;

vector<tuple<int, int, int>> edges; //간선의 정보
vector<int> min_dist; //최단 거리

bool bellmanFord(int start) { //보통의 벨만-포드와 달리 source가 INF 이어도 갱신해야함. 끊어진 그래프일 수 있기 때문
    int v = min_dist.size();

    min_dist[start] = 0; //시작점의 거리 0으로 초기화
    for (int i = 0; i < v - 1; i++) { //V번 비교
        bool isChanged = false; //최단 거리 갱신 있었는지 확인
        for (int j = 0; j < edges.size(); j++) {
            int source = get<0>(edges[j]);
            int dest = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            int new_dist = min_dist[source] + weight; //source를 거쳐서 dest로 가는 경로
            if (new_dist < min_dist[dest]) { //기존의 거리보다 짧은 경로라면 갱신
                if (i == (v - 2)) //근데 V번 째에 갱신된 것이라면 사이클이 형성된 것
                    return true;
                min_dist[dest] = new_dist;
                isChanged = true; //최단거리 업데이트가 있었음
            }
        }
        if (!isChanged) //최단거리 업데이트가 더 이상 없었으면 더 탐색할 필요 없음
            return false;
    }
    return false;
}

int main() {
    int TC, N, M, W, S, E, T;

    cin >> TC;
    for (int i = 0; i < TC; i++) {
        cin >> N >> M >> W;
        min_dist.assign(N + 1, INF); //최단 경로 초기화
        for (int j = 0; j < M; j++) { //양방향 간선
            cin >> S >> E >> T;
            edges.push_back(make_tuple(S, E, T));
            edges.push_back(make_tuple(E, S, T));
        }
        for (int j = 0; j < W; j++) { //단방향 간선
            cin >> S >> E >> T;
            edges.push_back(make_tuple(S, E, -T));
        }
        if(bellmanFord(1)) //1에서 시작해서 사이클 존재 여부 확인
            cout<<"YES\n";
        else
            cout<<"NO\n";
        edges.clear(); //튜플 초기화
    }
}