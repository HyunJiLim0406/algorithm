#include <iostream>

using namespace std;

int paper[2187][2187];
int nums[3]; //nums[0] = -1, nums[1] = 0, nums[2] = 1

bool isSame(int size, int row, int col, int num) {
    for (int i = row; i < (size + row); i++) {
        for (int j = col; j < (size + col); j++) {
            if (paper[i][j] != num)
                return false;
        }
    }
    return true;
}

void divide(int size, int row, int col) {
    int num = paper[row][col];

    if (isSame(size, row, col, num)) { //종이의 색이 모두 같음
        nums[num + 1]++;
    } else { //분할
        int resize = size / 3;
        for (int i = 0; i <= (resize * 2); i += resize)
            for (int j = 0; j <= (resize * 2); j += resize)
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
    cout << nums[0] << '\n' << nums[1] << '\n' << nums[2] << '\n';
}