#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, K, len = 0;

    cin >> N >> K;
    vector<int> sensor(N);
    for (int i = 0; i < N; i++)
        cin >> sensor[i];
    sort(sensor.begin(), sensor.end()); //정렬

    int tot_length = sensor[N - 1] - sensor[0]; //가장 먼 센서와 가까운 센서 사이의 거리
    priority_queue<int> pq;
    for (int i = 0; i < N - 1; i++) //인접한 센서들 간의 거리 차이
        pq.push(sensor[i + 1] - sensor[i]);
    while (pq.size() > N - K) { //가장 큰 거리차부터 빼기
        len += pq.top();
        pq.pop();
    }
    cout << tot_length - len;
}