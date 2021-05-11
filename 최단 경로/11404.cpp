#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> dist;

void floydWarshall(int v) { //플로이드-워셜
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
        }
    }
}

int main() {
    int n, m, a, b, c;

    cin >> n >> m;
    dist.assign(n + 1, vector<int>(n + 1, INF)); //INF로 초기화
    for (int i = 1; i <= n; i++) //자기 자신과의 거리는 0
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) { //같은 출발지-도착지일 수도 있으니까 최솟값인 간선만 넣기
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    floydWarshall(n);
    for (int i = 1; i <= n; i++) { //출력. 닿을 수 없는 곳은 0으로 출력
        for (int j = 1; j <= n; j++)
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }
}