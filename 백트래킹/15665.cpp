#include <iostream>
#include <algorithm>

using namespace std;

int input[8], arr[8];
int N, M;

void backtracking(int num) {
    if (num == M) { //출력
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int value = -1; //이전에 선택한 값 기억
    for (int i = 0; i < N; i++) {
        if (value != input[i]) { //이전 탐색 여부 검사
            value = input[i];
            arr[num] = input[i];
            backtracking(num + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    sort(input, input + N); //정렬
    backtracking(0);
}