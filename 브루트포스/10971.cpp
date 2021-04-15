#include <iostream>

using namespace std;

int matrix[10][10], N, cost, min_cost = -1;
bool visited[10];

//실시간으로 값을 갱신하는 코드는 갱신을 취소하는 부분을 반드시 넣어야 함
void backtracking(int start, int cur, int num) {
    if (num == N) { //종료 조건
        if (matrix[cur][start] != 0) { //처음 시작점으로 돌아올 수 있는가?
            cost += matrix[cur][start];
            if ((min_cost == -1) || (cost < min_cost)) //최소 비용 갱신
                min_cost = cost;
            cost -= matrix[cur][start];
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if ((matrix[cur][i] != 0) && !visited[i]) { //길이 있고 방문한 적 없는 도시라면
            visited[i] = true; //visited 처리
            cost += matrix[cur][i];
            if ((min_cost == -1) || (cost < min_cost)) //지금까지의 cost가 min_cost보다 작을 때만 min_cost일 가능성이 있음(=탐색할 가치가 있음)
                backtracking(start, i, num + 1);
            visited[i] = false; //unvisited 처리
            cost -= matrix[cur][i];
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
    }
    for (int i = 0; i < N; i++) { //도시 i를 출발점으로 했을 때의 최소 비용
        cost = 0;
        visited[i] = true; //visited 처리
        backtracking(i, i, 1);
        visited[i] = false; //unvisited 처리
    }
    cout << min_cost;
}