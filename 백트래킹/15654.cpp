#include <iostream>
#include <algorithm>

using namespace std;

int input[8], arr[8];
int N, M;
bool visited[8];

void backtracking(int num) {
    if (num == M) { //출력
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true; //visited 처리
            arr[num] = input[i];
            backtracking(num + 1);
            visited[i] = false; //unvisited 처리
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