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
    for (int i = 0; i < N; i++) { //중복출력이라 visited 필요없음
        arr[num] = input[i];
        backtracking(num + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    sort(input, input + N); //정렬
    backtracking(0);
}