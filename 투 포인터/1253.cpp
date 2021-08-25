#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

bool binarySearch(int left, int right, int idx) {
    while (left < right) {
        if (left == idx) { //자기 자신
            left++;
            continue;
        }
        if (right == idx) { //자기 자신
            right--;
            continue;
        }
        int num = arr[left] + arr[right];
        if (num == arr[idx]) //찾음
            return true;
        if (num > arr[idx])
            right--;
        else
            left++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, result = 0;

    cin >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); //정렬
    for (int i = 0; i < N; i++) { //모든 수에 대해 투포인터
        if (binarySearch(0, N - 1, i))
            result++;
    }
    cout << result;
}