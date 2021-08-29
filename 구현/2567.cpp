#include <iostream>

using namespace std;

bool board[100][100];
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void putPaper(int a, int b) { //색종이 붙이기
    for (int i = 90 - b; i < 100 - b; i++) {
        for (int j = a; j < a + 10; j++)
            board[i][j] = true;
    }
}

int cntSide(int row, int col) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) { //4방향에 대해 가장자리라면 둘레 추가
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if (nr < 0 || nr >= 100 || nc < 0 || nc >= 100 || !board[nr][nc])
            cnt++;
    }
    return cnt;
}

int calcPerimeter() {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j]) //붙은 색종이에 대해 둘레 판별
                result += cntSide(i, j);
        }
    }
    return result;
}

int main() {
    int n, a, b;

    cin >> n;
    while (n--) {
        cin >> a >> b;
        putPaper(a, b);
    }
    cout << calcPerimeter();
}