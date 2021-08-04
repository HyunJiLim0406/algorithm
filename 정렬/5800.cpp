#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K, N;

    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; j++)
            cin >> arr[j];
        sort(arr.begin(), arr.end(), greater<>());
        int num = 0;
        for (int j = 0; j < N - 1; j++) //가장 큰 인접한 점수 차이
            num = max(num, arr[j] - arr[j + 1]);
        cout << "Class " << i << '\n';
        cout << "Max " << arr[0] << ", Min " << arr[N - 1] << ", Largest gap " << num << '\n';
    }
}