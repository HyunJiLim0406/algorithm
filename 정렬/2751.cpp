#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, i;

    cin >> N;
    int* arr = new int[N];
    for (i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    for (i = 0; i < N; i++)
        cout << arr[i] << '\n';
}