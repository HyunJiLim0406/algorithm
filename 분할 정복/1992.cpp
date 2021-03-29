#include <iostream>

using namespace std;

int video[64][64];

bool isSame(int size, int col, int row, int color) {
    for (int i = col; i < (size + col); i++) {
        for (int j = row; j < (size + row); j++) {
            if (video[i][j] != color)
                return false;
        }
    }
    return true;
}

void divide(int size, int col, int row) {
    int color = video[col][row];

    if (isSame(size, col, row, color)) { //압축 가능
        cout << color;
    } else { //분할
        cout << '(';
        int resize = size / 2;
        for (int i = 0; i <= resize; i += resize) {
            for (int j = 0; j <= resize; j += resize)
                divide(resize, col + i, row + j);
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