#include <iostream>
using namespace std;

int main() { //1이면 1을 출력하는게 아니라 아무것도 출력하면 안되는 것이었음
    int N;

    cin >> N;
    while (N != 1) {
        for (int i = 2; i <= N; i++) {
            if (N % i == 0) {
                cout << i << '\n';
                N /= i;
                break;
            }
        }
    }
}