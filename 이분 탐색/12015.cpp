#include <iostream>

using namespace std;

int arr[1000001], dp[1000001];

int lowerBound(int left, int right, int key) { //lower bound를 찾는 함수
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dp[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1;
}

int lis(int n) {
    int length = 0;

    for (int i = 1; i <= n; i++) {
        int pos = lowerBound(1, length, arr[i]); //arr[i]이 들어가야 할 위치 반환
        dp[pos] = arr[i];
        if (pos > length) //증가 수열의 길이가 증가하는 상황
            length++;
    }
    return length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cout << lis(N) << '\n'; //길이 출력
}