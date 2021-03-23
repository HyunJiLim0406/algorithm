#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, };
int sum_arr[1001] = { 0, };

int withdraw(int N) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            sum_arr[i] += arr[j]; //각 사람이 걸리는 시간
    }
    for (int i = 0; i < N; i++)
        sum += sum_arr[i]; //총 걸리는 시간
    return sum;
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N); //걸리는 시간이 작은 사람이 앞에 오도록
    cout << withdraw(N);
}