#include <iostream>
using namespace std;

int main() {
    int N, num, count = 0;
    bool isPrime;

    cin >> N;
    for (int i = 0; i < N; i++) {
        isPrime = true;
        cin >> num;
        if (num == 1) //1이라면
            isPrime = false;
        else {
            for (int j = 2; j < num; j++) {
                if (num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            count++;
    }
    cout << count << '\n';
}