#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int temp, n;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    int N;
    int ring[100];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ring[i];
    for (int i = 1; i < N; i++) {
        int divisor = gcd(ring[0], ring[i]); //최대공약수 구하고
        cout << ring[0] / divisor << '/' << ring[i] / divisor << '\n'; //그걸로 각각 나누면 된다
    }
}