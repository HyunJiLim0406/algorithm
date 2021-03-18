#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, count, line, i, j;

    while (true) { //아까 그 어쩌구 체 재탕함. 이거 안쓰면 시간초과
        cin >> n;
        if (n == 0)
            break;
        count = 0;
        bool* isPrime = new bool[2 * n + 1];
        isPrime[0] = false;
        isPrime[1] = false;
        for (i = 2; i < 2 * n + 1; i++)
            isPrime[i] = true;
        line = sqrt(2 * n) + 1;
        for (i = 2; i <= line; i++) {
            if (isPrime[i]) {
                for (j = 2 * i; j < 2 * n + 1; j += i)
                    isPrime[j] = false;
            }
        }
        for (i = n + 1; i < 2 * n + 1; i++) {
            if (isPrime[i])
                count++;
        }
        cout << count << '\n';
    }
}