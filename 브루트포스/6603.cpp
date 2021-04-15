#include <iostream>

using namespace std;

int input[12], arr[12], k;

void backtracking(int idx, int num) {
    if (num == 6) { //종료 조건
        for (int i = 0; i < 6; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for (int i = idx + 1; i < k; i++) { //오름차순으로 탐색하기 위해
        arr[num] = input[i];
        backtracking(i, num + 1);
    }
}

int main() {
    while (true) {
        cin >> k;
        if (k == 0)
            break;

        for (int i = 0; i < k; i++)
            cin >> input[i];
        backtracking(-1, 0);
        cout << '\n';
    }
}