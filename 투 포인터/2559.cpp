#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 1; i < N; i++) //누적 합
        arr[i] += arr[i - 1];
    int result = arr[K - 1]; //초기값
    for (int i = K; i < N; i++) //최댓값 갱신
        result = max(result, arr[i] - arr[i - K]);
    cout << result;
}