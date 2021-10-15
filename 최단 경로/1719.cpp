#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7;

vector<vector<int>> graph, table;

void floydWarshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                int new_dist = graph[j][i] + graph[i][k];
                if (new_dist < graph[j][k]) { //최단 경로 갱신
                    graph[j][k] = new_dist;
                    table[j][k] = table[j][i];
                }
            }
        }
    }
}

int main() {
    int n, m, s, d, c;

    cin >> n >> m;
    graph.assign(n + 1, vector<int>(n + 1, INF));
    table.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) //자신과의 거리
        graph[i][i] = 0;

    while (m--) {
        cin >> s >> d >> c;
        graph[s][d] = c;
        graph[d][s] = c;
        table[s][d] = d;
        table[d][s] = s;
    }

    floydWarshall(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << "- ";
            else
                cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}