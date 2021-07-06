#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[100001];

int dpSquared(int n) {
    for (int i = 1; i <= n; i++) {
        int squared = sqrt(i); //제곱근
        int result = 1 + dp[i - (squared * squared)]; //greedy(?)하게 구한 초기값. 만약 32라면 1+dp[7]
        for (int j = squared - 1; j >= 1; j--) //비교하며 최솟값 찾기. 1+dp[16], 1+dp[23]...
            result = min(result, 1 + dp[i - (j * j)]);
        dp[i] = result;
    }
    return dp[n];
}

int main() {
    int N;

    cin >> N;
    cout << dpSquared(N);
}