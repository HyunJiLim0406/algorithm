#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> dist, table;

void floydWarshall(int v) { //플로이드-워셜
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                if (j == k) //자신과의 거리
                    continue;
                if (dist[j][k] > (dist[j][i] + dist[i][k])) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    table[j][k] = table[j][i];
                }
            }
        }
    }
}

vector<int> findRoute(int s, int d) {
    vector<int> ans;
    while (table[s][d] != d) {
        ans.push_back(table[s][d]);
        s = table[s][d];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;

    cin >> n >> m;
    dist.assign(n + 1, vector<int>(n + 1, INF));
    table.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c < dist[a][b]) {
            dist[a][b] = c;
            table[a][b] = b;
        }
    }
    floydWarshall(n);
    for (int i = 1; i <= n; i++) { //최단 경로 출력
        for (int j = 1; j <= n; j++)
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> route = findRoute(i, j);
            cout << route.size() + 2 << ' ' << i << ' ';
            for (int k = 0; k < route.size(); k++)
                cout << route[k] << ' ';
            cout << j << '\n';
        }
    }
}