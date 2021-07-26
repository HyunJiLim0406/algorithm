#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    int K, N;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> K >> N;
    vector<ll> num(K);
    for (int i = 0; i < K; i++)
        cin >> num[i];
    pq.push(1);

    int cnt = 0;
    while (cnt < N) { //N번째 수가 뽑힐 때 까지
        ll cur = pq.top();
        while (!pq.empty() && cur == pq.top()) //중복 제거
            pq.pop();
        for (int i = 0; i < K; i++) {
            if (cur * num[i] < INT32_MAX) //int 범위 내라면
                pq.push(cur * num[i]);
        }
        cnt++;
    }
    cout << pq.top();
}