#include <iostream>
#include <cmath>

using namespace std;

int N;
int tot_cnt = 0;
int visited[15] = {0,}; //2차원 bool 배열로 했더니 시간초과

bool promising(int index) {
    int k = 1;
    while (k < index) {
        if (visited[index] == visited[k] || abs(visited[index] - visited[k]) == (index - k))
            return false;
        k++;
    }
    return true;
}

void queens(int cnt) {
    if (cnt == N)
        tot_cnt++;
    else {
        for (int i = 1; i <= N; i++) {
            visited[cnt + 1] = i;
            if (promising(cnt + 1))
                queens(cnt + 1);
        }
    }
}

int main() {
    cin >> N;
    queens(0);
    cout << tot_cnt << '\n';
}