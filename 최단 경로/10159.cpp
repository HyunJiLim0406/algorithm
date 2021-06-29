#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> dist;

void floydWarshall(int N) { //플로이드 워셜
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (dist[j][i] && dist[i][k])
                    dist[j][k] = true;
            }
        }
    }
}

int main() {
    int N, M, a, b;

    cin >> N >> M;
    dist.assign(N + 1, vector<bool>(N + 1));
    vector<int> result(N + 1, N - 1); //초기화
    while (M--) {
        cin >> a >> b;
        dist[a][b] = true;
    }
    floydWarshall(N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j]) { //연결됐다면
                result[i]--;
                result[j]--;
            }
        }
    }
    for (int i = 1; i <= N; i++) //출력
        cout << result[i] << '\n';
}