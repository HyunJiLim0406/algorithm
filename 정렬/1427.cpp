
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, arr[10];

    cin >> N;
    int i = 0;
    while (N != 0) {
        arr[i++] = N % 10;
        N /= 10;
    }
    sort(arr, arr + i);
    for (int j = i - 1; j >= 0; j--)
        cout << arr[j];
}