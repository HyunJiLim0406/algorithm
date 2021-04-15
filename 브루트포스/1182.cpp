#include <iostream>

using namespace std;

int input[20], N, S, sum, cnt;

void backtracking(int idx) {
    for (int i = idx + 1; i < N; i++) { //중복되는 수열을 제거하기 위해
        sum += input[i]; //visited 처리
        if (sum == S) //S와 같다면 cnt++
            cnt++;
        backtracking(i);
        sum -= input[i]; //unvisited 처리
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    backtracking(-1);
    cout << cnt;
}