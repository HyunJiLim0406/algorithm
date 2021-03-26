#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> q;
    int N, K;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q.push(i);
    cout << "<";
    while (q.size() != 1) { //출력 때문에 1개 남으면 빠져나올 것
        for (int i = 0; i < K - 1; i++) { //뽑아야 할 수 나오기 직전까지 큐 옮겨줌
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">"; //마지막 남은 수 출력
}