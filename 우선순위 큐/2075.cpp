#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, input;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> input;
        if (pq.size() < N) //우선순위 큐의 크기가 N을 유지하도록
            pq.push(input);
        else if (pq.top() < input) { //큐의 최솟값(N번째 큰 수)보다 크다면 갱신
            pq.pop();
            pq.push(input);
        }
    }
    cout << pq.top();
}