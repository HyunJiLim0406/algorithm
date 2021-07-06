#include <iostream>

using namespace std;

int dp[16];

int main() {
    int N;

    cin >> N;
    if (N % 2 == 1) { //홀수인 경우
        cout << 0;
        return 0;
    }
    dp[1] = 3; //초기값
    for (int i = 2; i <= (N / 2); i++) {
        dp[i] += 3 * dp[i - 1]; //튀어나오지 않는 경우
        for (int j = i - 2; j >= 1; j--) { //튀어나오는 경우
            dp[i] += 2 * dp[j];
        }
        dp[i] += 2; //끝까지 튀어나오는 경우
    }
    cout << dp[N / 2];
}