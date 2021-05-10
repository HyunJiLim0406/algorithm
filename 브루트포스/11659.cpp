#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    int N, M, s, e, num;

    cin >> N >> M;
    arr.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) { //누적합
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << arr[e] - arr[s - 1] << '\n';
    }
}