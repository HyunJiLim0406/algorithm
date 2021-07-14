#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<double> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 1; i < N; i++) {
        if (arr[i] * arr[i - 1] > arr[i]) //이전 값과 곱하는게 원래의 수보다 크다면
            arr[i] *= arr[i - 1];
    }
    sort(arr.begin(), arr.end(), greater<>()); //정렬
    cout << fixed;
    cout.precision(3);
    cout << arr[0];
}