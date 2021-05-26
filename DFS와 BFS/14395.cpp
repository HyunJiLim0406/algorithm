#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;

string bfs(ll start, ll target) {
    set<ll> visited;
    queue<pair<ll, string>> q;
    visited.insert(start);
    q.push(make_pair(start, ""));

    while (!q.empty()) {
        ll cur = q.front().first; //현재 숫자
        string op = q.front().second; //지금까지의 연산
        q.pop();

        if (cur == target) //목표 숫자에 도달하면 연산 리턴
            return op;
        if (((cur * cur) <= target) && (visited.find(cur * cur) == visited.end())) { //목표 숫자 이하이며 미방문 숫자일 때
            visited.insert(cur * cur);
            q.push(make_pair(cur * cur, op + "*"));
        }
        if (((cur + cur) <= target) && (visited.find(cur + cur) == visited.end())) { //목표 숫자 이하이며 미방문 숫자일 때
            visited.insert(cur + cur);
            q.push(make_pair(cur + cur, op + "+"));
        }
        if (visited.find(0) == visited.end()) { //미방문 숫자일 때
            visited.insert(0);
            q.push(make_pair(0, op + "-"));
        }
        if (visited.find(1) == visited.end()) { //미방문 숫자일 때
            visited.insert(1);
            q.push(make_pair(1, op + "/"));
        }
    }
    return "-1"; //도달하지 못함
}

int main() {
    ll s, t;
    string result;

    cin >> s >> t;
    if (s == t)
        result = "0";
    else
        result = bfs(s, t);
    cout << result;
}