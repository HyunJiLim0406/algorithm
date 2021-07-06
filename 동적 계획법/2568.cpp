#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> result;
vector<pair<int, int>> arr;

int lis(int n) {
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i].second) - dp.begin(); //위치
        if (pos == dp.size()) //제일 큰 값
            dp.push_back(arr[i].second);
        dp[pos] = arr[i].second;
        arr[i].second = pos + 1; //위치 저장
    }
    int cur = dp.size();
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].second == cur) //lis에 포함되는 수
            cur--;
        else //lis에 포함되지 않는 수
            result.push(arr[i].first);
    }
    return n - dp.size(); //lis에 포함되지 않는 수의 개수 리턴
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.emplace_back(a, b);
    }
    sort(arr.begin(), arr.end()); //정렬
    cout << lis(n) << '\n';
    while (!result.empty()) { //출력
        cout << result.top() << '\n';
        result.pop();
    }
}