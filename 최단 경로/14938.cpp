
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> min_dist; //최단 거리

void floydWarshall() { //플로이드-워셜
    int v = min_dist.size();
    for (int i = 1; i < v; i++) {
        for (int j = 1; j < v; j++) {
            for (int k = 1; k < v; k++)
                min_dist[j][k] = min(min_dist[j][k], min_dist[j][i] + min_dist[i][k]);
        }
    }
}

int main() {
    int n, m, r, a, b, l, result = 0;
    vector<int> item; //각 정점의 아이템 갯수

    cin >> n >> m >> r;
    min_dist.assign(n + 1, vector<int>(n + 1, INF));
    item.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) //아이템 정보 입력
        cin >> item[i];
    for (int i = 0; i < r; i++) { //연결 정보 입력
        cin >> a >> b >> l;
        min_dist[a][b] = l;
        min_dist[b][a] = l;
    }
    for (int i = 1; i <= n; i++) //자기 자신과의 거리는 0
        min_dist[i][i] = 0;
    floydWarshall(); //플로이드-워셜
    for (int i = 1; i <= n; i++) { //정점 i에 떨어졌을 때
        int cnt = 0; //정점 i에서 얻을 수 있는 아이템의 수
        for (int j = 1; j <= n; j++) { //수색범위 내에 있는 정점이라면 아이템 획득
            if (min_dist[i][j] <= m)
                cnt += item[j];
        }
        result = max(result, cnt); //최댓값 갱신
    }
    cout << result;
}