#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> dist, before;

void floydWarshall(int v) { //플로이드-워셜
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                if (j == k)
                    continue;
                if (dist[j][k] > (dist[j][i] + dist[i][k])) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    before[j][k] = i; //이전 정점 갱신
                }
            }
        }
    }
}

vector<int> v;
void findRoute(int start, int end) { //왜 string으로 안될까??
    if (before[start][end] == start){ //재귀 종료
        v.push_back(start);
        v.push_back(end);
        return;
    }
    int next_node = before[start][end];
    findRoute(start, next_node); //이전
    v.pop_back();
    findRoute(next_node, end); //이후
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;

    cin >> n >> m;
    dist.assign(n + 1, vector<int>(n + 1, INF));
    before.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        before[a][b] = a;
    }
    floydWarshall(n);
    for (int i = 1; i <= n; i++) { //최단 경로 출력
        for (int j = 1; j <= n; j++)
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) //갈 수 없음
                cout << 0;
            else { //경로 출력
                v.clear();
                findRoute(i, j);
                cout<<v.size()<<' ';
                for(int k=0;k<v.size();k++)
                    cout<<v[k]<<' ';
            }
            cout<<'\n';
        }
    }
}