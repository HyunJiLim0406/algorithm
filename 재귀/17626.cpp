#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> dp;

void dpSquared(int N) {
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int r = sqrt(i);
        for (int j = r; j >= 1; j--)
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
    }
}

int main() {
    int N;

    cin >> N;
    dp.assign(N + 1, 5);
    dpSquared(N);
    cout << dp[N];
}