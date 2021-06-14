#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> arr;

ll fillDp(int N, int target) {
    vector<vector<ll>> dp(N - 1, vector<ll>(21, 0));
    dp[0][arr[0]] = 1; //초기값
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (!dp[i - 1][j]) //i-1까지의 수로 숫자 j를 만들 수 없다면
                continue;
            if (j - arr[i] >= 0) //arr[i]를 빼도 0이상이면
                dp[i][j - arr[i]] += dp[i - 1][j];
            if (j + arr[i] <= 20) //arr[i]를 더해도 20이하면
                dp[i][j + arr[i]] += dp[i - 1][j];
        }
    }
    return dp[N - 2][target];
}

int main() {
    int N, target;

    cin >> N;
    arr.assign(N - 1, 0);
    for (int i = 0; i < N - 1; i++)
        cin >> arr[i];
    cin >> target;
    cout << fillDp(N, target);
}