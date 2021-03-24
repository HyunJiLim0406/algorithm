
#include <iostream>
using namespace std;

int binomial(int N, int K) {
    int m = 1, c = 1;
    int temp_N = N;
    int temp_K = K;

    if (N / 2 < K) { //5C3 같은 경우
        K = N - K;
        temp_K = K;
    }
    for (int i = 0; i < K; i++) {
        m *= temp_N;
        c *= temp_K;
        temp_N--;
        temp_K--;
    }
    return m / c;
}

int main() {
    int N, K;

    cin >> N >> K;
    cout << binomial(N, K);
}