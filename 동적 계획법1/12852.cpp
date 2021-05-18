#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<pair<int, int>> dp;

pair<int, int> findMin(int i1, int i2) { //두 인덱스 중 연산이 더 작은 dp를 찾음
    pair<int, int> result;
    result.first = min(dp[i1].first, dp[i2].first) + 1; //연산 횟수
    if (dp[i1].first == (result.first - 1)) //어떤 인덱스에서 넘어온 것인지
        result.second = i1;
    else
        result.second = i2;
    return result;
}

vector<int> fillDp(int N) {
    vector<int> result;
    pair<int, int> min_pair;
    for (int i = 2; i <= N; i++) {
        min_pair = make_pair(dp[i - 1].first + 1, i - 1); //초기값은 i-1
        if (i % 2 == 0) //2로 나누어 떨어진다면 비교
            min_pair = findMin(i / 2, min_pair.second);
        if (i % 3 == 0) //3으로 나누어 떨어진다면 비교
            min_pair = findMin(i / 3, min_pair.second);
        dp[i] = min_pair; //갱신
    }
    int cur = N;
    while (cur != -1) { //경로 추적
        result.push_back(cur);
        cur = dp[cur].second;
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    dp.assign(N + 1, make_pair(0, -1));
    vector<int> dp_list = fillDp(N);
    cout << dp_list.size() - 1 << '\n'; //연산 횟수 출력
    for (int i = 0; i < dp_list.size(); i++) //연산 과정 출력
        cout << dp_list[i] << ' ';
}