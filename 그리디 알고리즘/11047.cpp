#include <iostream>
using namespace std;

int coin[11];

int greedyCoin(int N, int K) {
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) { //큰 수부터
        if (K / coin[i] != 0) {
            cnt = cnt + (K / coin[i]);
            K %= coin[i];
        }
    }
    return cnt;
}

int main() {
    int N, K;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
    cout << greedyCoin(N, K);
}