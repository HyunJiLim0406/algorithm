#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> dp;

void fillDp(vector<int> arr, int N) {
    for (int gap = 0; gap < N; gap++) { //길이가 1인 수열부터 N인 수열까지
        for (int start = 0; start < N - gap; start++) {
            int end = start + gap;
            //길이 = 1 -> true, 첫 숫자와 마지막 숫자가 같고, 그 안쪽 범위가 펠린드롬이거나 길이가 2 -> true
            if (gap == 0 || arr[start] == arr[end] && (dp[start + 1][end - 1] || gap == 1))
                dp[start][end] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, E;

    cin >> N;
    dp.assign(N, vector<bool>(N, false));
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    fillDp(arr, N);
    cin >> M;
    while (M--) {
        cin >> S >> E;
        cout << dp[S - 1][E - 1] << '\n';
    }
}