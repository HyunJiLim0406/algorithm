#include <iostream>
using namespace std;
const int MAX = 8;

int N, M;
int arr[MAX];

void backNM(int cnt, int flag) { //2번 + 3번
    if (cnt == M) { //배열 끝까지 완성하면 출력
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else {
        for (int i = flag; i < N; i++) {
            arr[cnt] = i + 1;
            backNM(cnt + 1, i); //가지 아래로 내려감
        }
    }
}

int main() {
    cin >> N >> M;
    backNM(0, 0);
}