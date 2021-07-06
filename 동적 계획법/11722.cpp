#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001], dp[1001];

int lis(int n) {
    int length = 0;

    dp[0] = 1001;
    for (int i = 1; i <= n; i++) {
        for (int j = length; j >= 0; j--) {
            if (arr[i] < dp[j]) {
                dp[j + 1] = arr[i];
                if (j == length) //최장 길이 증가
                    length++;
                break;
            }
        }
    }
    return length;
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cout << lis(N) << '\n'; //길이 출력
}