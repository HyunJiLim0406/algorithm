#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp; //명우가 먼저 시작했을 때 근우의 점수
vector<int> arr, sum;

int fillDp(int N) {
    for (int gap = 1; gap < N; gap++) {
        for (int start = 1; start <= N - gap; start++) {
            int end = start + gap;
            int value = max(arr[end] + dp[start][end - 1], arr[start] + dp[start + 1][end]); //근우가 먼저 시작했을 때 얻을 수 있는 최대 점수
            dp[start][end] = sum[end] - sum[start - 1] - value; //명우가 먼저 시작했을 때의 근우의 점수로 바꾸기
        }
    }
    return sum[N] - dp[1][N];
}

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        dp.assign(N + 1, vector<int>(N + 1, 0));
        arr.assign(N + 1, 0);
        sum.assign(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            sum[i] = arr[i] + sum[i - 1]; //누적합
        }
        cout << fillDp(N) << '\n';
    }
}