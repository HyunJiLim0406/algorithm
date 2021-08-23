#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N;

    cin >> N;
    vector<ll> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        int j = 3;
        while (i - j >= 0) { //선택 + 복사 + 붙여넣기 <- 합쳐서 생각하기
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
            j++;
        }
    }
    cout << dp[N];
}