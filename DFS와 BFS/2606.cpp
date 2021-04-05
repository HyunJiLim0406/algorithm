#include <iostream>

using namespace std;

int matrix[101][101], cnt;
bool visited[101] = {false}; //정점의 방문 여부

void dfs(int cur, int max) { //재귀함수로 구현
    for (int i = 1; i <= max; i++) {
        if (matrix[cur][i] == 1 && !visited[i]) {
            cnt++;
            visited[i] = true; //방문 체크한 뒤 재귀 호출
            dfs(i, max);
        }
    }
}

int main() {
    int N, M, first, second;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> first >> second;
        matrix[first][second] = 1;
        matrix[second][first] = 1;
    }
    visited[1] = true;
    dfs(1, N);
    cout << cnt;
}