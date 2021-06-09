#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int>> board;

bool isSquare(int num, int r, int c) {
    for (int i = r; i < r + num; i++) {
        for (int j = c; j < c + num; j++) {
            if (!board[i][j]) //하나라도 0이면 false
                return false;
        }
    }
    return true;
}

bool isPromise(int num) {
    for (int i = 0; i <= n - num; i++) {
        for (int j = 0; j <= m - num; j++) {
            if (isSquare(num, i, j)) //해당 크기 사각형 존재
                return true;
        }
    }
    return false;
}

int upperSearch(int left, int right) { //upper-bound
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPromise(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right * right; //넓이
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int one_cnt = 0;
    string input;

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j] - '0';
            if (board[i][j] == 1) //1의 개수
                one_cnt++;
        }
    }
    int right = sqrt(one_cnt); //사각형의 최대 길이
    cout << upperSearch(1, right);
}