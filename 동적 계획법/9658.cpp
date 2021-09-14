#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<bool> dp(N + 1, true);
    dp[1] = dp[3] = false; //지는 경우
    for (int i = 5; i <= N; i++) {
        if (dp[i - 1] && dp[i - 3] && dp[i - 4]) //모두 상근이가 이겼다면 지게 됨
            dp[i] = false;
    }
    cout << (dp[N] ? "SK" : "CY");
}