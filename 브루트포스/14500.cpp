#include <iostream>
#include <utility>

using namespace std;

int matrix[500][500];
int local_max, N, M;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void horn(int row, int col, int sum) { //matrix[row][col]가 + 모양의 정 가운데가 될 것
    int cnt = 0;
    int arr[4] = {0}; //상하좌우의 값 저장

    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;

        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M)) { //범위에 들어오면 저장
            cnt++;
            arr[i] = matrix[nr][nc];
            sum += matrix[nr][nc];
        }
    }

    if ((cnt == 3) && (sum > local_max)) //보라색 조각과 같은 모양
        local_max = sum;
    else if (cnt == 4) { // + 모양
        for (int i = 0; i < 4; i++) { //상하좌우의 값 중 하나씩 빼보며 최댓값 확인
            int tmp = sum;

            tmp -= arr[i];
            if (tmp > local_max)
                local_max = tmp;
        }
    }
    return;
}

void tetromino(int row, int col, int num, int sum) {
    if (num == 4) { //백트래킹 종료 조건
        if (sum > local_max)
            local_max = sum;
        return;
    }

    int value = matrix[row][col];
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;

        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (matrix[nr][nc] != 0)) { //범위에 들어왔고 unvisited 라면
            matrix[row][col] = 0; //visited 처리
            tetromino(nr, nc, num + 1, sum + matrix[nr][nc]); //백트래킹 탐색
            matrix[row][col] = value; //unvisited 처리
        }
    }
}

int main() {
    int result = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];
    }

    local_max = 0; //matrix[i][j]를 포함해서 만들 수 있는 모든 블럭의 최댓값
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            horn(i, j, matrix[i][j]); //보라색 블럭 처리
            tetromino(i, j, 1, matrix[i][j]); //나머지 모양 처리

            if (local_max > result) //최댓값?
                result = local_max;
        }
    }
    cout << result;
}