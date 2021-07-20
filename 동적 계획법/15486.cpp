#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<pair<int, int>> schedule;

int backtracking(int N, int day) {
    if (day > N) //상담 불가
        return 0;
    if (dp[day] == -1) { //초기화 된 적 없다면
        dp[day] = backtracking(N, day + 1); //그날의 상담을 하지 않고 넘어감
        if (day + schedule[day].first <= N) //상담 하기
            dp[day] = max(dp[day], backtracking(N, day + schedule[day].first) + schedule[day].second);
    }
    return dp[day];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    dp.assign(N + 1, -1); //마지막 날 하루짜리 상담을 할 수 있으므로 N+1 크기 할당
    schedule.assign(N, make_pair(0, 0));
    for (int i = 0; i < N; i++)
        cin >> schedule[i].first >> schedule[i].second;
    cout << backtracking(N, 0);
}