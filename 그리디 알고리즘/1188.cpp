#include <iostream>

using namespace std;

int gcd(int N, int M) {
    int tmp = 0;
    if (N < M)
        swap(N, M);
    while (M) {
        tmp = N % M;
        N = M;
        M = tmp;
    }
    return N;
}

int main() { //N개의 소시지를 이어 붙인다면
    int N, M;

    cin >> N >> M;
    cout << M - gcd(N, M);
}