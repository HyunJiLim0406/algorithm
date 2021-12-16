#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, m, p, l;
    string cmd;

    vector<int> list(100001, 0); //난이도 저장
    priority_queue<pii> max_heap;
    priority_queue<pii, vector<pii>, greater<>> min_heap;

    cin >> n;
    while (n--) { //문제 추가
        cin >> p >> l;
        list[p] = l;
        max_heap.push({l, p});
        min_heap.push({l, p});
    }

    cin >> m;
    while (m--) {
        cin >> cmd >> p;
        if (cmd == "add") { //문제 추가
            cin >> l;
            list[p] = l;
            max_heap.push({l, p});
            min_heap.push({l, p});
        }
        if (cmd == "recommend") { //문제 추천
            int num = 0;
            if (p == 1) { //가장 어려운 문제
                while (list[max_heap.top().second] != max_heap.top().first) //실제로 존재하는 문제가 나올 때까지
                    max_heap.pop();
                num = max_heap.top().second;
            }
            if (p == -1) { //가장 쉬운 문제
                while (list[min_heap.top().second] != min_heap.top().first) //실제로 존재하는 문제가 나올 때까지
                    min_heap.pop();
                num = min_heap.top().second;
            }
            cout << num << '\n';
        }
        if (cmd == "solved") //문제 풀이
            list[p] = 0;
    }
}