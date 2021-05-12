#include <iostream>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

map<ll, int> dist;

int bfs(ll source, ll target) { //bfs 탐색
    queue<ll> q;
    dist[source] = 1;
    q.push(source);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        if (cur == target) //목표 숫자가 되면 리턴
            return dist[target];
        if (((cur * 2) <= target) && !dist[cur * 2]) { //2를 곱하기
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
        if (((cur * 10 + 1) <= target) && !dist[cur * 10 + 1]) { //1을 수의 가장 오른쪽에 추가하기
            dist[cur * 10 + 1] = dist[cur] + 1;
            q.push(cur * 10 + 1);
        }
    }
    return -1;
}

int main() {
    ll A, B;

    cin >> A >> B;
    cout << bfs(A, B);
}