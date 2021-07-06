#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<tuple<int, int, int>>> dp;

int dpPipe() {
    dp[1][2] = make_tuple(1, 0, 0); //초기값
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (((i == 1) && (j == 2)) || (map[i][j] == 1)) //초기값이거나 벽이면 continue
                continue;
            int horizontal = 0, vertical = 0, diagonal = 0;
            if (map[i][j - 1] == 0) //가로로 놓여있다면
                horizontal = get<0>(dp[i][j - 1]) + get<2>(dp[i][j - 1]); //그 이전은 가로거나 대각선
            if (map[i - 1][j] == 0) //세로로 놓여있다면
                vertical = get<1>(dp[i - 1][j]) + get<2>(dp[i - 1][j]); //그 이전은 세로거나 대각선
            if ((map[i][j - 1] == 0) && (map[i - 1][j] == 0) && (map[i - 1][j - 1] == 0)) //대각선으로 놓여있다면
                diagonal = get<0>(dp[i - 1][j - 1]) + get<1>(dp[i - 1][j - 1]) + get<2>(dp[i - 1][j - 1]); //그 이전은 가로, 세로, 대각선
            dp[i][j] = make_tuple(horizontal, vertical, diagonal);
        }
    }
    return get<0>(dp[N][N]) + get<1>(dp[N][N]) + get<2>(dp[N][N]); //3가지 경우를 전부 더한 값
}

int main() {
    cin >> N;
    map.assign(N + 1, vector<int>(N + 1, 1));
    dp.assign(N + 1, vector<tuple<int, int, int>>(N + 1, make_tuple(0, 0, 0)));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    }
    cout << dpPipe() << '\n';
}