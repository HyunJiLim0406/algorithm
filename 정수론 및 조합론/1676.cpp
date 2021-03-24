#include <iostream>
#include <algorithm>
using namespace std;

int fact(int N) {
    int two_cnt = 0, five_cnt = 0;

    for (int i = 2; i <= N; i *= 2)
        two_cnt += N / i;
    for (int i = 5; i <= N; i *= 5)
        five_cnt += N / i;

    return min(two_cnt, five_cnt); //2와 5가 모여야 한 쌍이므로 둘 중 작은 수로
}

int main() {
    int N;

    cin >> N;
    cout << fact(N);
}