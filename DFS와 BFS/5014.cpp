#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
vector<int> dist;

bool isPromise(int num) { //범위내에 있는 미방문 층인지
    if (num < 1 || num > F || dist[num] != -1)
        return false;
    return true;
}

int bfs() {
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == G) //목적지 도착
            return dist[cur];
        if (isPromise(cur + U)) { //올라가기
            dist[cur + U] = dist[cur] + 1;
            q.push(cur + U);
        }
        if (isPromise(cur - D)) { //내려가기
            dist[cur - D] = dist[cur] + 1;
            q.push(cur - D);
        }
    }
    return -1; //도달 불가능
}

int main() {
    cin >> F >> S >> G >> U >> D;
    dist.assign(F + 1, -1);
    int result = bfs();
    if (result == -1)
        cout << "use the stairs";
    else
        cout << result;
}