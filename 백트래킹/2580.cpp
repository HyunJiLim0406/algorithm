#include <iostream>
using namespace std;

int sudoku[9][9];
int hole_cnt = 0;
bool found = false;

struct hole {
    int col, row;
};

hole* sudo_hole = new hole[81]; //빈공간 저장

bool promising(int hole_index, int candidate) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (sudoku[sudo_hole[hole_index].row][i] == candidate) //같은 열에 있나?
            return false;
        if (sudoku[i][sudo_hole[hole_index].col] == candidate) //같은 행에 있나?
            return false;
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if ((sudo_hole[hole_index].row / 3) == (i / 3) && (sudo_hole[hole_index].col / 3) == (j / 3)) { //같은 구역에 있나?(이거 생각하느라 고생함)
                if (sudoku[i][j] == candidate)
                    return false;
            }
        }
    }
    return true;
}

void fill_sudoku(int cnt) {
    if (cnt == hole_cnt) { //다 찾으면 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true; //첫 해 찾았으면 바로 나오기
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (promising(cnt, i)) {
                sudoku[sudo_hole[cnt].row][sudo_hole[cnt].col] = i; //아래로 내려감
                fill_sudoku(cnt + 1);
                if (found)
                    return;
                sudoku[sudo_hole[cnt].row][sudo_hole[cnt].col] = 0; //위로 다시 올라감(이거 빼먹어서 고생함. 돌아갈 길을 만들어 두자)
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                sudo_hole[hole_cnt].row = i;
                sudo_hole[hole_cnt++].col = j;
            }
        }
    }
    fill_sudoku(0);
}