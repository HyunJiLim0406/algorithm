#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0,};

int main() {
    int N, sum = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N); //걸리는 시간이 작은 사람이 앞에 오도록

    for (int i = 0; i < N; i++)
        sum += (arr[i] * (N - i));
    cout << sum;
}