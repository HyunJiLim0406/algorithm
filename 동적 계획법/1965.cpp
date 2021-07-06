#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> arr) { //증가하는 부분 수열
    vector<int> dp;
    for (int i = 0; i < arr.size(); i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //이분 탐색으로 위치 찾기
        if (pos == dp.size()) //최댓값이라면
            dp.push_back(arr[i]);
        else //그렇지 않다면
            dp[pos] = arr[i];
    }
    return dp.size();
}

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lis(arr);
}