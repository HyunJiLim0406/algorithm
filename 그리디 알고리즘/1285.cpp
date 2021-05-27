#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cntCoin(vector<vector<int>> board, int num, int size, int min_num) {
    for (int i = 0; i < size; i++) { //뒤집기
        if ((num & (1 << i)) == 0)
            continue;
        for (int j = 0; j < size; j++) //뒤집어야할 행이라면 xor 연산으로 토글
            board[i][j] ^= 1;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) { //각 열에 대해
        int cnt = 0;
        for (int j = 0; j < size; j++) {
            if (board[j][i] == 0) //뒷면 개수
                cnt++;
        }
        sum += min(cnt, size - cnt); //앞면 or 뒷면 중 더 작은 수를 택함
        if (sum >= min_num) //현재의 최솟값보다 크면 더이상 탐색하지 않음
            return min_num;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string input;
    vector<vector<int>> board;

    cin >> N;
    board.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++)
            board[i][j] = (input[j] == 'H') ? 1 : 0;
    }

    int result = N * N; //초기값
    for (int i = 0; i < (1 << N); i++) //모든 경우의 수 뒤집어보기(행)
        result = cntCoin(board, i, N, result);
    cout << result;
}