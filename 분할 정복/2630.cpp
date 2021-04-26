#include <iostream>

using namespace std;

int paper[128][128];
int colors[2]; //colors[0] = white, colors[1] = blue

bool isSame(int size, int row, int col, int color) {
    for (int i = row; i < (size + row); i++) {
        for (int j = col; j < (size + col); j++) {
            if (paper[i][j] != color)
                return false;
        }
    }
    return true;
}

void divide(int size, int row, int col) {
    int color = paper[row][col];

    if (isSame(size, row, col, color)) { //종이의 색이 모두 같음
        colors[color]++;
    } else { //분할
        int resize = size / 2;
        for (int i = 0; i <= resize; i += resize)
            for (int j = 0; j <= resize; j += resize)
                divide(resize, row + i, col + j);
    }
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    }
    divide(N, 0, 0);
    cout << colors[0] << '\n' << colors[1] << '\n';
}