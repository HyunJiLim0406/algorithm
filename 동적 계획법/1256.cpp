#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<vector<int>> dp;

void fillDp(int N, int M) { //i개의 a와 j개의 z로 만들 수 있는 문자열의 조합
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            dp[i][j] = min(INF, dp[i - 1][j] + dp[i][j - 1]);
    }
}

string findStr(int N, int M, int K) {
    string str = "";
    if (N == 0) { //더이상 a가 없음
        while (M--)
            str += 'z';
    } else if (M == 0) { //더이상 z가 없음
        while (N--)
            str += 'a';
    } else {
        if (dp[N - 1][M] >= K) //a를 붙인 문자열의 수가 K개 이상이라면 -> a
            str = 'a' + findStr(N - 1, M, K);
        else //a를 붙인 문자열의 수가 K개 미만이라면 -> z
            str = 'z' + findStr(N, M - 1, K - dp[N - 1][M]); //a가 접두사인 문자열의 수를 뺸 것
    }
    return str;
}

int main() {
    int N, M, K;

    cin >> N >> M >> K;
    dp.assign(N + 1, vector<int>(M + 1, 1));
    fillDp(N, M);
    if (dp[N][M] < K) //K번째 문자열을 만들 수 없음
        cout << -1;
    else
        cout << findStr(N, M, K);
}