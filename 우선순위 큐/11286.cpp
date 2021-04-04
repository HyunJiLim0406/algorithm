#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) { //a가 부모 노드, b가 자식 노드 일 때. true 반환하면 swap
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    int N, x;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else
            pq.push(x);
    }
}