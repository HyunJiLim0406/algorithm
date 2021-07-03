#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second != p2.second)
        return p1.second < p2.second; //빨리 끝나는 것
    return p1.first < p2.first; //빨리 시작하는 것
}

int assignClass(int n) {
    multiset<int, greater<>> s; //내림차순 멀티셋
    for (int i = 0; i < n; i++) {
        auto iter = s.lower_bound(arr[i].first); //현재 시작시간과 가장 근접한 것
        if (iter != s.end()) //이미 존재하는 강의실의 종료 시간 갱신 위해 삭제
            s.erase(iter);
        s.insert(arr[i].second); //갱신 or 강의실 추가
    }
    return s.size();
}

int main() {
    int N;

    cin >> N;
    arr.assign(N, make_pair(0, 0));
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), cmp);
    cout << assignClass(N);
}