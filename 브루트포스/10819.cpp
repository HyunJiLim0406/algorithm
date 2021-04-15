#include <iostream>

using namespace std;

int input[8], arr[8], N, result;
bool visited[8];

int calc() { //arr에 모인 값에 대해 문제의 계산을 하는 함수
    int sum = 0;

    for (int i = 0; i < N - 1; i++)
        sum += abs(arr[i] - arr[i + 1]);
    return sum;
}

void backtracking(int num) { //백트래킹하며 배열 생성. next_permutation으로도 구현할 수 있을듯
    if (num == N) { //종료 조건
        int arr_sum = calc();
        if (arr_sum > result) //최댓값 갱신
            result = arr_sum;
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
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    backtracking(0);
    cout << result;
}