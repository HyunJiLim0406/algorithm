#include <iostream>
#include <vector>

using namespace std;

int result = 26;
vector<int> paper_cnt(5);
vector<vector<int>> board(10, vector<int>(10));

int usedPaper() { //지금까지 사용한 종이의 수
    int cnt = 0;
    for (int i = 0; i < 5; i++)
        cnt += paper_cnt[i];
    return cnt;
}

bool isPromiseSize(int r, int c, int size) { //이 크기의 종이 부착 가능한지 확인
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (i >= 10 || j >= 10 || !board[i][j]) //범위에서 벗어나거나 종이가 없음
                return false;
        }
    }
    return true;
}

void changeBoard(int r, int c, int size, int mark) { //종이를 붙이거나 떼기
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++)
            board[i][j] = mark;
    }
}

void backtracking(int idx) {
    if (usedPaper() > result) //더이상 탐색할 필요 없음
        return;
    if (idx == 100) { //끝까지 확인
        result = min(result, usedPaper()); //최솟값 갱신
        return;
    }
    int row = idx / 10; //행
    int col = idx % 10; //열
    if (board[row][col]) { //종이가 있을 때
        bool isPos = false;
        for (int i = 4; i >= 0; i--) { //N 크기의 종이를 붙였다면 그보다 작은 종이는 당연히 붙일 수 있음
            if (!isPos && !isPromiseSize(row, col, i + 1))
                continue;
            isPos = true;
            if (paper_cnt[i] < 5) { //해당 크기의 종이를 하나 더 쓸 수 있는지
                changeBoard(row, col, i + 1, 0); //종이 붙이기
                paper_cnt[i]++; //종이 사용 표시
                backtracking(idx + 1);
                changeBoard(row, col, i + 1, 1); //종이 떼기
                paper_cnt[i]--; //종이 사용 취소
            }
        }
    } else //종이가 없을 때
        backtracking(idx + 1);
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cin >> board[i][j];
    }
    backtracking(0);
    cout << ((result == 26) ? -1 : result);
}