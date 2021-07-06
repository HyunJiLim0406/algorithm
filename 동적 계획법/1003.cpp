#include <iostream>
using namespace std;

void fibo_cnt(int num) {
    int zero_cnt[41] = { 0, };
    int one_cnt[41] = { 0, };
    for (int i = 0; i <= num; i++) {
        if (i == 0) {
            zero_cnt[i] = 1;
            one_cnt[i] = 0;
        }
        else if (i == 1) {
            zero_cnt[i] = 0;
            one_cnt[i] = 1;
        }
        else {
            zero_cnt[i] = zero_cnt[i - 1] + zero_cnt[i - 2];
            one_cnt[i] = one_cnt[i - 1] + one_cnt[i - 2];
        }
    }
    cout << zero_cnt[num] << ' ' << one_cnt[num] << '\n';
}

int main() {
    int T;

    cin >> T;
    int* N = new int[T];
    for (int i = 0; i < T; i++)
        cin >> N[i];
    for (int i = 0; i < T; i++)
        fibo_cnt(N[i]);
}