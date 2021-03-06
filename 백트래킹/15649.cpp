#include <iostream>
using namespace std;
const int MAX = 8;

int N, M;
int arr[MAX];
bool visited[MAX] = { 0, }; //false로 초기화

void backNM(int cnt) {
    if (cnt == M) { //배열 끝까지 완성하면 출력
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                arr[cnt] = i + 1;
                visited[i] = true; //방문 표시
                backNM(cnt + 1); //가지 아래로 내려감
                visited[i] = false; //위로 다시 올라감
            }
        }
    }
}

int main() {
    cin >> N >> M;
    backNM(0);
}