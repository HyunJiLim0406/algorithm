#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ans = 0;

    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    for (int i = 0; i < N; i++)
        ans += (A[i] * B[i]);
    cout << ans;
}