#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> dist;

void floydWarshall() { //플로이드-워셜
    int size = dist.size();
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            for (int k = 1; k < size; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
        }
    }
}

int main() { //풀리긴 했는데 플로이드-워셜로 푸는 문제가 아니라고 함
    int N, M, X, s, d, w;

    cin >> N >> M >> X;
    dist.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) //자기 자신과의 거리는 0
        dist[i][i] = 0;
    for (int i = 0; i < M; i++) { //거리 초기 입력
        cin >> s >> d >> w;
        dist[s][d] = w;
    }
    floydWarshall();
    int max_dist = 0;
    for (int i = 1; i <= N; i++) //i-X-i의 거리 중 최댓값 구하기
        max_dist = max(max_dist, dist[i][X] + dist[X][i]);
    cout << max_dist;
}