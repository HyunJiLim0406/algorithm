#include <iostream>
#include <algorithm>

using namespace std;

int A[1000000];

bool binarySearch(int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == A[mid])
            return true;
        else if (target < A[mid]) //왼쪽 탐색
            right = mid - 1;
        else if (target > A[mid]) //오른쪽 탐색
            left = mid + 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, target;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N); //정렬

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> target;
        cout << binarySearch(target, 0, N - 1) << '\n';
    }

}
