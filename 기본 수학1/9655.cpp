#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;
    int share = N / 3;
    int remain = N % 3;
    if ((share + remain) % 2 == 1)
        cout << "SK";
    else
        cout << "CY";
}