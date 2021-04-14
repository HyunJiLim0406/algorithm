#include <iostream>

using namespace std;

int cnt;

void backtracking(int num) {
    if (num == 0) { //0이면 카운트 추가
        cnt++;
        return;
    }

    for (int i = 3; i >= 1; i--) { //3부터 1까지 뺄 수 있는지 확인
        if ((num - i) >= 0)
            backtracking(num - i);
    }
}

int main() {
    int t, n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cnt = 0;
        cin >> n;
        backtracking(n);
        cout << cnt << '\n';
    }
}