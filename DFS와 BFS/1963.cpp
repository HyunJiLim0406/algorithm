#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

vector<int> prime; //1000~9999 사이의 소수
map<int, vector<int>> graph; //소수간의 연결관계

void eratos() { //에라토스테네스의 체
    vector<bool> is_prime;
    is_prime.assign(10000, true);
    is_prime[0] = is_prime[1] = false;

    int line = sqrt(9999) + 1;
    for (int i = 2; i <= line; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < 10000; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 1000; i < 10000; i++) {
        if (is_prime[i])
            prime.push_back(i);
    }
}

bool isConnect(int x, int y) { //두 수가 연결 가능한지 확인
    int diff_cnt = 0; //다른 숫자의 수
    for (int i = 0; i < 4; i++) {
        if ((x % 10) != (y % 10))
            diff_cnt++;
        x /= 10;
        y /= 10;
    }
    return diff_cnt == 1; //다른 숫자가 1개여야 true
}

int bfs(int start, int end) {
    queue<int> q;
    map<int, int> dist; //최단 거리

    dist[start] = 1;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) //종료지점이면 리턴
            return dist[cur] - 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (dist[graph[cur][i]] == 0) { //미방문 정점이면 갱신
                dist[graph[cur][i]] = dist[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    return -1;
}

int main() {
    int T, num1, num2;

    eratos();
    for (int i = 0; i < prime.size(); i++) { //연결관계 생성
        vector<int> tmp;
        for (int j = 0; j < prime.size(); j++) {
            if (isConnect(prime[i], prime[j]))
                tmp.push_back(prime[j]);
        }
        graph[prime[i]] = tmp;
    }

    cin >> T;
    while (T--) {
        cin >> num1 >> num2;
        cout << bfs(num1, num2) << '\n';
    }
}