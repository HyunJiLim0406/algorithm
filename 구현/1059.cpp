#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, n;

    cin >> L;
    vector<int> arr(L);
    for (int i = 0; i < L; i++)
        cin >> arr[i];
    cin >> n;
    sort(arr.begin(), arr.end());
    if (binary_search(arr.begin(), arr.end(), n)) //좋은 구간이 없음
        cout << 0;
    else { //n의 양쪽에 있는 수를 찾아서 구간 계산
        int left = *--lower_bound(arr.begin(), arr.end(), n);
        int right = *upper_bound(arr.begin(), arr.end(), n);
        cout << (n - left) * (right - n) - 1;
    }
}