#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, input;
    priority_queue<ll, vector<ll>, greater<>> pq;

    cin >> n >> m;
    while (n--) {
        cin >> input;
        pq.push(input);
    }
    while (m--) {
        ll num[2];
        for (int i = 0; i < 2; i++) { //제일 작은 수 2개
            num[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < 2; i++) //더해서 넣기
            pq.push(num[0] + num[1]);
    }
    ll result = 0;
    while (!pq.empty()) { //결과
        result += pq.top();
        pq.pop();
    }
    cout << result;
}