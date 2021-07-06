#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> dp(68);

void fillDp() { //미리 끝까지 채워놓기
    for (int i = 0; i < 68; i++) {
        if (i < 2)
            dp[i] = 1;
        else if (i == 2)
            dp[i] = 2;
        else if (i == 3)
            dp[i] = 4;
        else
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }
}

int main() {
    int t, n;

    fillDp();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}