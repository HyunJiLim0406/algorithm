#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int MODULAR = 1e9;

int fillDp(int N) {
    ll result = 0;
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(10, vector<ll>(1 << 10)));
    for (int i = 1; i < 10; i++) //초기화
        dp[0][i][1 << i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < (1 << 10); k++) { //0~1023
                if (j != 0) //j-1 뒤에 j 붙이기
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                if (j != 9) //j+1 뒤에 j 붙이기
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                dp[i][j][k | (1 << j)] %= MODULAR; //나머지 연산
            }
        }
    }
    for (int i = 0; i < 10; i++) { //0~9를 전부 사용한 경우만 더하기
        result += dp[N - 1][i][1023];
        result %= MODULAR;
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    cout << fillDp(N);
}