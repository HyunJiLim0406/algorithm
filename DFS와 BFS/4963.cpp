#include <iostream>

using namespace std;

int matrix[50][50];
int h, w;

void dfs(int col, int row) {
    matrix[col][row] = 0; //visited 처리
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nc = col + i;
            int nr = row + j;
            if ((nc >= 0) && (nc < h) && (nr >= 0) && (nr < w) && matrix[nc][nr]) //범위 내에 있는 육지인가?
                dfs(nc, nr);
        }
    }
}

int main() {
    int cnt;

    while (true) {
        cin >> w >> h;
        if ((w == 0) && (h == 0)) //종료
            break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cin >> matrix[i][j];
        }
        cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == 1) { //특정 육지에 대해 연결된 모든 육지 찾음
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout<<cnt<<'\n';
    }
}