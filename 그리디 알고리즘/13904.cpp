#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<pair<int, int>> assignment(N);
    for (int i = 0; i < N; i++)
        cin >> assignment[i].first >> assignment[i].second;
    sort(assignment.begin(), assignment.end(), greater<>()); //마감일 기준 내림차순 정렬

    int day = assignment[0].first, idx = 0, result = 0;
    priority_queue<int> pq;
    while (day) { //해당 날짜에 해결할 과제
        while (idx < N) { //오늘 해결할 수 있는 모든 과제를 우선순위 큐에 넣기
            if (assignment[idx].first < day)
                break;
            pq.push(assignment[idx].second);
            idx++;
        }
        if (!pq.empty()) { //가장 큰 값 하나만
            result += pq.top();
            pq.pop();
        }
        day--;
    }
    cout << result;
}