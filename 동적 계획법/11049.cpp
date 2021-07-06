#include <iostream>
#include <vector>

using namespace std;

int fillDp(vector<pair<int, int>> matrix, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int gap = 1; gap < N; gap++) {
        for (int start = 0; start < N - gap; start++) { //파일 합치기와 유사
            int end = start + gap;
            dp[start][end] = 1e9; //초기화
            for (int mid = end - 1; mid >= start; mid--)
                dp[start][end] = min(dp[start][end],
                                     dp[start][mid] + dp[mid + 1][end] +
                                     matrix[start].first * matrix[mid].second * matrix[end].second);
        }
    }
    return dp[0][N - 1];
}

int main() {
    int N;

    cin >> N;
    vector<pair<int, int>> matrix(N);
    for (int i = 0; i < N; i++)
        cin >> matrix[i].first >> matrix[i].second;
    cout << fillDp(matrix, N);
}