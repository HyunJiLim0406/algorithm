#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001], dp[1001];

int lis(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) //증가 수열 관계라면
                dp[i] = max(dp[i], dp[j] + arr[i]); //해당 인덱스의 최대 합과 비교하여 갱신
        }
        result = max(result, dp[i]); //최대 합 갱신
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cout << lis(N) << '\n'; //최대 합 출력
}