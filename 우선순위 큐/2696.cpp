#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t, m, num;

    cin >> t;
    while (t--) {
        priority_queue<int> max_heap; //최대힙
        priority_queue<int, vector<int>, greater<>> min_heap; //최소힙

        cin >> m;
        cout << m / 2 + 1 << '\n';
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cin >> num;
            if (max_heap.empty() || max_heap.top() >= num) //힙이 비어있거나 중앙값보다 작은 값이면 최대힙으로
                max_heap.push(num);
            else //아니면 최소힙으로
                min_heap.push(num);
            if (((int) max_heap.size() - (int) min_heap.size()) >= 2) { //최대힙이 최소힙보다 원소가 2이상 많다면
                int tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
            }
            if (max_heap.size() < min_heap.size()) { //최소힙이 최대힙보다 크다면
                int tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }
            if (i % 2 == 0) { //출력
                cout << max_heap.top() << ' ';
                cnt++;
                if (cnt == 10) { //10개마다 엔터
                    cout << '\n';
                    cnt = 0;
                }
            }
        }
        cout << '\n';
    }
}