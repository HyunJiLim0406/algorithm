#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 1; i < N; i++) //이전 원소 쓰거나 말거나
            arr[i] += max(arr[i - 1], 0);
        sort(arr.begin(), arr.end(), greater<>());
        cout << arr[0] << '\n';
    }
}