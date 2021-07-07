#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, input;

    cin >> N;
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++) {
        cin >> input;
        dq.emplace_back(i + 1, input); //풍선 번호와 숫자
    }
    while (!dq.empty()) {
        cout << dq.front().first << ' '; //풍선 번호 출력
        int num = dq.front().second; //이동 횟수
        dq.pop_front();
        if (num >= 0) { //오른쪽으로 이동
            num--;
            while (num--) {
                pair<int, int> tmp = dq.front();
                dq.push_back(tmp);
                dq.pop_front();
            }
        } else { //왼쪽으로 이동
            num = -num;
            while (num--) {
                pair<int, int> tmp = dq.back();
                dq.push_front(tmp);
                dq.pop_back();
            }
        }
    }
}