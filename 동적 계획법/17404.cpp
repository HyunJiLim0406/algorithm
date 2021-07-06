#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int cost[1000][3], N;

int dpPaint(int first) {
    int dp[1000][3];

    for (int i = 0; i < 3; i++) {
        if (i == first) //첫번째 집과 두번째 집을 같은 색으로 칠할 수 없음
            dp[1][i] = INF;
        else //첫번째 집의 색으로 칠함
            dp[1][i] = cost[1][i] + cost[0][first];
    }
    for (int i = 2; i < N; i++) { //최소비용
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int result = INF;
    for (int i = 0; i < 3; i++) { //첫번째 집과 마지막 집의 색이 같은 경우를 제외하고 최소 비용 갱신
        if (i != first)
            result = min(result, dp[N - 1][i]);
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    }
    int min_cost = INF;
    for (int i = 0; i < 3; i++) //첫번째 집의 색을 바꾸면서 최소 비용 갱신
        min_cost = min(min_cost, dpPaint(i));
    cout << min_cost;
}