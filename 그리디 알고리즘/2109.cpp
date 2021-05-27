#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

bool cmp(const pair<ll, int> &p1, const pair<ll, int> &p2) {
    return p1.second > p2.second;
}

int main() {
    int n;
    vector<pair<ll, int>> info;
    priority_queue<ll> pq;

    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    info.assign(n, make_pair(0, 0));
    for (int i = 0; i < n; i++)
        cin >> info[i].first >> info[i].second;
    sort(info.begin(), info.end(), cmp); //d기준 내림차순 정렬

    int day = info[0].second, idx = 0;
    ll sum = 0;
    while (day) { //각각의 날에 대해서 강연 정하기
        while ((idx < n) && (info[idx].second >= day)) { //갈 수 있는 강연이라면 큐에 삽입
            pq.push(info[idx].first);
            idx++;
        }
        if (!pq.empty()) { //우선순위 큐에서 가장 큰 p값을 꺼냄
            sum += pq.top();
            pq.pop();
        }
        day--;
    }
    cout << sum;
}