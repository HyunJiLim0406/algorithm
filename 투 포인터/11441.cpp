#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, num, a, b;

    cin >> N;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> num;
        arr[i] = arr[i - 1] + num; //누적 합
    }
    cin >> M;
    while (M--) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}