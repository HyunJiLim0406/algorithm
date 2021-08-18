#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
pair<int, int> dir[4] = {{0,  1},  //우
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {-1, 0}}; //상

void rotate(int cnt, int N, int M) {
    for (int i = 0; i < cnt; i++) {
        int s = arr[i][i]; //시작점 저장
        int row = i, col = i, d = 0;

        do {
            int nr = row + dir[d].first;
            int nc = col + dir[d].second;
            if (nr < i || nr >= (N - i) || nc < i || nc >= (M - i)) { //범위 벗어나면 방향 바꾸기
                d++;
                nr = row + dir[d].first;
                nc = col + dir[d].second;
            }
            arr[row][col] = arr[nr][nc];
            row = nr;
            col = nc;
        } while (row != i || col != i); //돌아올 때까지
        arr[i + 1][i] = s; //마지막 위치
    }
}

int main() {
    int N, M, R;

    cin >> N >> M >> R;
    arr.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    int cnt = min(N, M) / 2; //돌려야하는 배열의 수
    while (R--) //한칸씩 R번 돌리기
        rotate(cnt, N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}