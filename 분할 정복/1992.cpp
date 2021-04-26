#include <iostream>

using namespace std;

int video[64][64];

bool isSame(int size, int row, int col, int color) {
    for (int i = row; i < (size + row); i++) {
        for (int j = col; j < (size + col); j++) {
            if (video[i][j] != color)
                return false;
        }
    }
    return true;
}

void divide(int size, int row, int col) {
    int color = video[row][col];

    if (isSame(size, row, col, color)) { //압축 가능
        cout << color;
    } else { //분할
        cout << '(';
        int resize = size / 2;
        for (int i = 0; i <= resize; i += resize) {
            for (int j = 0; j <= resize; j += resize)
                divide(resize, row + i, col + j);
        }
        cout << ')';
    }
}

int main() {
    int N;
    string temp[64];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            video[i][j] = temp[i][j] - '0';
    }
    divide(N, 0, 0);
}