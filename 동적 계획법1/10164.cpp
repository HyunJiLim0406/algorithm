#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

void fillDp(int sr, int sc, int er, int ec) {
    for (int i = sr; i <= er; i++) {
        for (int j = sc; j <= ec; j++) {
            if (i == sr || j == sc) //시작점과 행 또는 열이 같을 때
                dp[i][j] = dp[sr][sc];
            else //위에서 오거나 아래에서 오거나
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}

int main() {
    int N, M, K;

    cin >> N >> M >> K;
    dp.assign(N, vector<int>(M, 0));
    if (K == 0) //K가 0이라면 맨 마지막 좌표를 가리키도록
        K = N * M;
    int kr = (K - 1) / M; //K의 행
    int kc = (K - 1) % M; //K의 열
    dp[0][0] = 1; //초기화
    fillDp(0, 0, kr, kc); //시작점 ~ K
    fillDp(kr, kc, N - 1, M - 1); //K ~ 도착점
    cout << dp[N - 1][M - 1]; //도착점의 경로 수 촐력
}