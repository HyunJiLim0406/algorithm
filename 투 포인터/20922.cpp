#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int SIZE = 100000;

int findLen(int n, int k, vector<int> &arr) {
    vector<int> cnt(SIZE + 1, 0); //각 원소 등장 횟수
    int left = 0, right = 0, ans = 0;
    set<int> s; //k번보다 많이 등장한 원소
    cnt[arr[0]]++;

    while (left <= right && right < n) {
        if (s.empty()) { //k번보다 많이 등장한 원소가 없다면 범위 늘리기
            ans = max(ans, (right - left) + 1);
            right++;
            if (right == n)
                break;
            cnt[arr[right]]++;
            if (cnt[arr[right]] > k) //k번 초과
                s.insert(arr[right]);
        } else {
            cnt[arr[left]]--;
            if (cnt[arr[left]] == k) //원래 k번 초과했을 것
                s.erase(arr[left]);
            left++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findLen(n, k, arr);
}