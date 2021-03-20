#include <iostream>
using namespace std;

int main() {
    int N, M, sum, i, j, k, gap = 300001, gap_sum = 0;

    cin >> N >> M;
    int* card = new int[N];
    for (int a = 0; a < N; a++)
        cin >> card[a];
    for (i = 0; i < N - 2; i++) {
        for (j = i + 1; j < N - 1; j++) {
            for (k = j + 1; k < N; k++) {
                sum = card[i] + card[j] + card[k];
                if (sum <= M) { //합이 M보다 작은지
                    if (gap > (M - sum)) { //차이 계산해서 갱신
                        gap = M - sum;
                        gap_sum = sum;
                    }
                }
            }
        }
    }
    cout << gap_sum << endl;
}