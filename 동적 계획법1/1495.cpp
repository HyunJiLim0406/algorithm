#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> dp;
vector<int> diff;

void fillDp(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i][j]) {
                if (j - diff[i] >= 0) //볼륨을 줄일 수 있다면
                    dp[i + 1][j - diff[i]] = true;
                if (j + diff[i] <= M) //볼륨을 키울 수 있다면
                    dp[i + 1][j + diff[i]] = true;
            }
        }
    }
}

int main() {
    int N, S, M;

    cin >> N >> S >> M;
    dp.assign(N + 1, vector<bool>(M + 1, false));
    dp[0][S] = true; //초기값
    diff.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> diff[i];
    fillDp(N, M);
    int result = -1;
    for (int i = M; i >= 0; i--) { //가능한 가장 큰 볼륨
        if (dp[N][i]) {
            result = i;
            break;
        }
    }
    cout << result;
}