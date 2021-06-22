#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> graph;

void floydWarshall(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            for (int k = 1; k <= size; k++) {
                if (graph[j][i] && graph[i][k]) //연결 확인
                    graph[j][k] = true;
            }
        }
    }
}

int main() {
    int N, M, a, b;

    cin >> N >> M;
    graph.assign(N + 1, vector<bool>(N + 1, false));
    vector<int> connected(N + 1, 0);
    while (M--) {
        cin >> a >> b;
        graph[a][b] = true;
    }
    floydWarshall(N);

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j]) { //연결됐다면
                connected[i]++;
                connected[j]++;
                if (connected[i] == N - 1) //전부 연결 확인
                    cnt++;
                if (connected[j] == N - 1) //전부 연결 확인
                    cnt++;
            }
        }
    }
    cout << cnt;
}