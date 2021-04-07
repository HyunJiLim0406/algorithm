#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

//범위 초과 때문에 상하좌우 한줄씩 추가
int matrix[52][52], M, N;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> pos) { //인접한 모든 배추를 찾는 dfs
    for (int i = 0; i < 4; i++) { //현위치의 상하좌우 좌표를 col, row에 저장
        int col = pos.first + dir[i].first;
        int row = pos.second + dir[i].second;
        if (matrix[col][row] == 1) { //확인한 적 없는 배추(leaf)
            matrix[col][row] = 0; //방문 체크
            pair<int, int> next_pos = {col, row};
            dfs(next_pos); //재귀 호출
        }
    }
}

int findBug() {
    int cnt = 0; //총 벌레수

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == 1) { //확인한 적 없는 배추(root)
                cnt++; //총 벌레 수 증가
                matrix[i][j] = 0;
                pair<int, int> start = {i, j};
                dfs(start); //인접한 모든 배추를 찾음
            }
        }
    }
    return cnt;
}

int main() {
    int T, K, col, row;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            cin >> row >> col;
            matrix[col + 1][row + 1] = 1;
        }
        cout << findBug() << '\n'; //총 벌레수 출력
        for (int i = 0; i < 52; i++) //2차원 배열 초기화
            memset(matrix[i], 0, sizeof(int) * 52);
    }
}