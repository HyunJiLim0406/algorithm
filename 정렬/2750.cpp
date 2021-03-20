#include <iostream>
using namespace std;

void insertion_sort(int* arr, int n) { //삽입정렬
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

int main() {
    int N, i;

    cin >> N;
    int* arr = new int[N];
    for (i = 0; i < N; i++)
        cin >> arr[i];
    insertion_sort(arr, N);
    for (i = 0; i < N; i++)
        cout << arr[i] << endl;
}