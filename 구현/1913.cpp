#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
pair<int, int> dir[4] = {{1,  0},   //하
                         {0,  1},   //우
                         {-1, 0},   //상
                         {0,  -1}}; //좌

pair<int, int> fillMatrix(int N, int target) {
    pair<int, int> pos;
    int row = 0, col = 0, d = 0;
    for (int i = N * N; i > 0; i--) {
        matrix[row][col] = i; //숫자 채우기
        if (i == target) //찾는 숫자라면
            pos = make_pair(row + 1, col + 1);
        row += dir[d].first;
        col += dir[d].second;
        if ((row < 0) || (row >= N) || (col < 0) || (col >= N) || matrix[row][col]) { //방향을 바꿔야함
            row = row - dir[d].first + dir[(d + 1) % 4].first;
            col = col - dir[d].second + dir[(d + 1) % 4].second;
            d = (d + 1) % 4;
        }
    }
    return pos;
}

int main() {
    int N, target;

    cin >> N >> target;
    matrix.assign(N, vector<int>(N, 0));
    pair<int, int> result = fillMatrix(N, target);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    cout << result.first << ' ' << result.second;
}