#include <iostream>
#include <vector>

using namespace std;

//가능한 모든 조합에 대해 일의 자리가 가장 큰 값
int maxSum(vector<int> &arr) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++)
                ans = max(ans, (arr[i] + arr[j] + arr[k]) % 10);
        }
    }
    return ans;
}

int main() {
    int n, ans = 0, max_value = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> arr(5, 0);
        for (int j = 0; j < 5; j++)
            cin >> arr[j];

        int sum = maxSum(arr);
        if (max_value <= sum) { //최댓값 갱신
            max_value = sum;
            ans = i;
        }
    }
    cout << ans;
}