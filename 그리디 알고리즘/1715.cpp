#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, num;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> N;
    while (N--) {
        cin >> num;
        pq.push(num);
    }
    int result = 0;
    while (pq.size() >= 2) { //우선 순위 큐의 원소가 2개 이상 있을 때
        int x = pq.top();
        pq.pop();

        int y = pq.top();
        pq.pop();

        result += x + y; //가장 작은 것 2개 합치기
        pq.push(x + y);
    }
    cout << result;
}