#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> arr) {
    vector<int> dp;
    for (int i = 0; i < arr.size(); i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i]의 위치
        if (pos == dp.size()) //가장 큰 수라면
            dp.push_back(arr[i]);
        else //가장 큰 수가 아니라면
            dp[pos] = arr[i];
    }
    return dp.size(); //가장 긴 증가하는 부분 수열의 길이
}

int main() {
    int N;

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << N - lis(arr);
}