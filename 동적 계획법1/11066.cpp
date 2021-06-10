#include <iostream>
#include <vector>

using namespace std;

int fillDp(vector<int> sum, int K) {
    vector<vector<int>> dp(K + 1, vector<int>(K + 1, 1e9)); //i부터 j까지의 파일을 합치는 최솟값
    for (int i = 0; i < K; i++) { //i~j에서 ~을 담당. ex) i=2 -> dp[1][3], dp[2][4]...
        for (int j = 1; j <= K - i; j++) { //i=2 -> j=1...K-2
            if (i == 0) //자기자신과 합치는 비용은 0원
                dp[j][j + i] = 0;
            for (int k = j; k < j + i; k++) //dp[1][3] -> dp[1][1]+dp[2][3], dp[1][2]+dp[3][3]
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
        }
    }
    return dp[1][K];
}

int main() {
    int T, K, num;

    cin >> T;
    while (T--) {
        cin >> K;
        vector<int> sum(K + 1, 0); //누적합
        for (int i = 1; i <= K; i++) {
            cin >> num;
            sum[i] = sum[i - 1] + num;
        }
        cout << fillDp(sum, K) << '\n';
    }
}