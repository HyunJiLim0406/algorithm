#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> fifth; //5구역 표시
pair<int, int> dir[4] = {{1,  -1},  //왼쪽 아래
                         {1,  1},   //오른쪽 아래
                         {-1, 1},   //오른쪽 위
                         {-1, -1}}; //왼쪽 위

void findFifth(int n, vector<int> d1_d2, int x, int y) {
    bool is_in = false; //경계선 안에 있는지
    fifth.assign(n + 1, vector<bool>(n + 1, false));
    int nx = x, ny = y, d = 0, len_idx = 0, cnt = 0;
    do {
        fifth[nx][ny] = true; //경계선 표시
        if (cnt == d1_d2[len_idx]) { //방향을 바꿔야 함
            len_idx = (len_idx + 1) % 2;
            d = (d + 1) % 4;
            cnt = 0;
        }
        nx += dir[d].first;
        ny += dir[d].second;
        cnt++;
    } while (nx != x || ny != y); //되돌아 올 때까지

    for (int i = x + 1; i < x + d1_d2[0] + d1_d2[1]; i++) {
        for (int j = 1; j <= n; j++) {
            if (fifth[i][j]) //i번째 행의 왼쪽 경계선인지 오른쪽 경계선인지
                is_in = !(is_in);
            if (is_in) //경계선 내부
                fifth[i][j] = true;
        }
    }
}

int calcSector(int n, int d1, int d2, int x, int y) {
    vector<int> arr(5, 0);
    findFifth(n, {d1, d2}, x, y); //5구역 표시
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (fifth[i][j]) //5구역
                arr[4] += board[i][j];
            else if (i < x + d1 && j <= y) //1구역
                arr[0] += board[i][j];
            else if (i <= x + d2 && j > y) //2구역
                arr[1] += board[i][j];
            else if (i >= x + d1 && j < y - d1 + d2) //3구역
                arr[2] += board[i][j];
            else if (i > x + d2 && j >= y - d1 + d2) //4구역
                arr[3] += board[i][j];
        }
    }
    sort(arr.begin(), arr.end()); //정렬
    return arr[4] - arr[0];
}

int splitSector(int n, int d1, int d2, int cur_min) {
    int result = cur_min;
    int sx = 1, ex = n - (d1 + d2), sy = 1 + d1, ey = n - d2; //해당 d1, d2에서 가능한 x, y 범위
    for (int x = sx; x <= ex; x++) {
        for (int y = sy; y <= ey; y++)
            result = min(result, calcSector(n, d1, d2, x, y)); //최솟값 갱신
    }
    return result;
}

int main() {
    int N, result = 40001;

    cin >> N;
    board.assign(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i + j < N) //가능한 d1, d2라면
                result = splitSector(N, i, j, result);
        }
    }
    cout << result;
}