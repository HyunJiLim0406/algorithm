#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r_len = 3, c_len = 3; //행의 길이, 열의 길이
int board[100][100];

void calcR() {
    int next_c_len = c_len; //R 연산 후 열의 길이
    for (int i = 0; i < r_len; i++) {
        vector<pair<int, int>> tmp(101, make_pair(0, 0));
        for (int j = 0; j < c_len; j++) {
            if (board[i][j]) //0이 아니라면
                tmp[board[i][j]] = make_pair(tmp[board[i][j]].first + 1, board[i][j]); //등장횟수, 숫자
        }
        sort(tmp.begin(), tmp.end()); //정렬

        int cnt = 0;
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j].second != 0) {
                board[i][cnt++] = tmp[j].second; //숫자
                board[i][cnt++] = tmp[j].first; //등장횟수
                if (cnt == 100) //100개가 넘어가면 안됨
                    break;
            }
        }
        next_c_len = max(next_c_len, cnt); //다음번 열의 길이 갱신
        while (cnt < r_len) //더 짧아졌을 경우 0 채워주기
            board[i][cnt++] = 0;
    }
    c_len = next_c_len; //갱신
}

void calcC() {
    int next_r_len = r_len; //C 연산 후 행의 길이
    for (int i = 0; i < c_len; i++) {
        vector<pair<int, int>> tmp(101, make_pair(0, 0));
        for (int j = 0; j < r_len; j++) {
            if (board[j][i]) //0이 아니라면
                tmp[board[j][i]] = make_pair(tmp[board[j][i]].first + 1, board[j][i]); //등장횟수, 숫자
        }
        sort(tmp.begin(), tmp.end()); //정렬

        int cnt = 0;
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j].second != 0) {
                board[cnt++][i] = tmp[j].second; //숫자
                board[cnt++][i] = tmp[j].first; //등장횟수
                if (cnt == 100) //100개가 넘어가면 안됨
                    break;
            }
        }
        next_r_len = max(next_r_len, cnt); //다음번 행의 길이 갱신
        while (cnt < c_len) //더 짧아졌을 경우 0 채워주기
            board[cnt++][i] = 0;
    }
    r_len = next_r_len; //갱신
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, k;

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
    }
    int result = -1;
    for (int i = 0; i <= 100; i++) {
        if (board[r - 1][c - 1] == k) { //종료 조건
            result = i;
            break;
        }
        if (r_len >= c_len)
            calcR();
        else
            calcC();
    }
    cout << result;
}