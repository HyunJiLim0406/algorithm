#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, result;

vector<vector<int>> upMove(vector<vector<int>> board) { //위로 이동
    vector<vector<int>> n_board; //새로운 보드
    n_board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (board[j][i] == 0) //블럭이 없음
                continue;
            bool is_checked = false;
            int next_block = j + 1; //합쳐질 가능성이 있는 블럭
            while (next_block < N) { //범위내에 있을 때
                if (board[j][i] == board[next_block][i]) { //두 블럭이 같으면 합침
                    is_checked = true;
                    n_board[cnt++][i] = (board[j][i] * 2);
                    j = next_block; //다음에 탐색할 j
                    break;
                }
                if (board[next_block][i] != 0) //다음 위치가 빈칸이 아닌데 다른 숫자
                    break;
                next_block++;
            }
            if (!is_checked && (board[j][i] != 0)) //합쳐진 블럭 없으면 그대로 투입
                n_board[cnt++][i] = board[j][i];
        }
    }
    return n_board;
}

vector<vector<int>> downMove(vector<vector<int>> board) { //아래로 이동
    vector<vector<int>> n_board;
    n_board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int cnt = N - 1;
        for (int j = N - 1; j >= 0; j--) {
            if (board[j][i] == 0)
                continue;
            bool is_checked = false;
            int next_block = j - 1;
            while (next_block >= 0) {
                if (board[j][i] == board[next_block][i]) {
                    is_checked = true;
                    n_board[cnt--][i] = (board[j][i] * 2);
                    j = next_block;
                    break;
                }
                if (board[next_block][i] != 0)
                    break;
                next_block--;
            }
            if (!is_checked && (board[j][i] != 0))
                n_board[cnt--][i] = board[j][i];
        }
    }
    return n_board;
}

vector<vector<int>> leftMove(vector<vector<int>> board) { //왼쪽으로 이동
    vector<vector<int>> n_board;
    n_board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0)
                continue;
            bool is_checked = false;
            int next_block = j + 1;
            while (next_block < N) {
                if (board[i][j] == board[i][next_block]) {
                    is_checked = true;
                    n_board[i][cnt++] = (board[i][j] * 2);
                    j = next_block;
                    break;
                }
                if (board[i][next_block] != 0)
                    break;
                next_block++;
            }
            if (!is_checked && (board[i][j] != 0))
                n_board[i][cnt++] = board[i][j];
        }
    }
    return n_board;
}

vector<vector<int>> rightMove(vector<vector<int>> board) { //오른쪽으로 이동
    vector<vector<int>> n_board;
    n_board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int cnt = N - 1;
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] == 0)
                continue;
            bool is_checked = false;
            int next_block = j - 1;
            while (next_block >= 0) {
                if (board[i][j] == board[i][next_block]) {
                    is_checked = true;
                    n_board[i][cnt--] = (board[i][j] * 2);
                    j = next_block;
                    break;
                }
                if (board[i][next_block] != 0)
                    break;
                next_block--;
            }
            if (!is_checked && (board[i][j] != 0))
                n_board[i][cnt--] = board[i][j];
        }
    }
    return n_board;
}

void dfs(int cnt, vector<vector<int>> board) {
    if (cnt == 5) { //5번 움직이면 최댓값 갱신
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                result = max(result, board[i][j]);
        }
        return;
    }
    dfs(cnt + 1, upMove(board)); //위로 이동
    dfs(cnt + 1, downMove(board)); //아래로 이동
    dfs(cnt + 1, leftMove(board)); //왼쪽으로 이동
    dfs(cnt + 1, rightMove(board)); //오른쪽으로 이동
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> board;

    cin >> N;
    board.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    dfs(0, board);
    cout << result;
}