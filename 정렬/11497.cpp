#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        int result = 0;

        cin >> N;
        vector<int> arr(N), tmp(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end()); //정렬
        for (int i = 0; i < N; i++) { //순서대로 양끝부터 채워나감
            if (i % 2 == 0)
                tmp[i / 2] = arr[i];
            if (i % 2 == 1)
                tmp[N - (i / 2) - 1] = arr[i];
        }
        for (int i = 0; i < N; i++)
            result = max(result, abs(tmp[i] - tmp[(i + 1) % N]));
        cout << result << '\n';
    }
}