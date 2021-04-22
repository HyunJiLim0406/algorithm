#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char board[50][50];

int cntCandy(int N) {
    int max_cnt = 0, cnt;
    char cur;

    for (int i = 0; i < N; i++) {
        cur = 'A';
        cnt = 1;
        for (int j = 0; j < N; j++) { //같은 열끼리 카운트
            if (cur == board[i][j]) { //연속된 사탕
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else { //불연속
                cnt = 1;
                cur = board[i][j];
            }
        }
        cur = 'A';
        cnt = 1;
        for (int j = 0; j < N; j++) { //같은 행끼리 카운트
            if (cur == board[j][i]) { //연속된 사탕
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else { //불연속
                cnt = 1;
                cur = board[j][i];
            }
        }
    }
    return max_cnt;
}

int main() {
    string input;
    int N, max_candy = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++)
            board[i][j] = input[j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char candy = board[i][j];
            if (((i + 1) < N) && (candy != board[i + 1][j])) { //아래랑 바꾸기
                swap(board[i + 1][j], board[i][j]);
                max_candy = max(max_candy, cntCandy(N)); //최대 사탕 계산
                swap(board[i + 1][j], board[i][j]);
            }
            if (((j + 1) < N) && (candy != board[i][j + 1])) { //오른쪽이랑 바꾸기
                swap(board[i][j], board[i][j + 1]);
                max_candy = max(max_candy, cntCandy(N)); //최대 사탕 계산
                swap(board[i][j], board[i][j + 1]);
            }
        }
    }
    cout << max_candy;
}