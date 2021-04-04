#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq; //greater면 min heap
    int N, x, mid;

    cin >> N;
    cin >> mid; //첫 입력은 중앙값
    cout << mid << '\n';
    for (int i = 1; i < N; i++) {
        cin >> x;
        if (x > mid) //중앙값보다 큰 값은 최소 힙으로
            min_pq.push(x);
        else //중앙값보다 작거나 같은 값은 최대 힙으로
            max_pq.push(x);

        int interval = max_pq.size() - min_pq.size(); //두 우선순위 큐의 크기 차이는 항상 0 또는 1이어야 함.
        if (interval > 0) { //최대 힙의 원소가 더 많은 경우
            min_pq.push(mid);
            mid = max_pq.top();
            max_pq.pop();
        } else if (interval < -1) { //최소 힙의 원소가 더 많은 경우
            max_pq.push(mid);
            mid = min_pq.top();
            min_pq.pop();
        }
        cout << mid << '\n';
    }
}