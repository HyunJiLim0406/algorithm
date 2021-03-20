#include <iostream>
using namespace std;

int split(int num) {
    int sum = num;
    while (num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i < N; i++) {
        if (split(i) == N) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}