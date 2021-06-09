#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> board;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int result = 0;
    string input;

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j] - '0';
            if(board[i][j]) //가장자리에 있는 1 체크
                result = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j]) { //점화식
                board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
                result = max(result, board[i][j]);
            }
        }
    }
    cout << result * result; //넓이
}