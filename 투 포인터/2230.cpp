#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int minDiff(int N, int M) {
    int left = 0, right = 0, result = 2 * 1e9 + 1;
    while (left < N && right < N) {
        if (left > right) { //순서가 반전됐다면
            right++;
            continue;
        }
        int diff = arr[right] - arr[left]; //차이
        if (diff >= M) { //M 이상이면 result 갱신하고 왼쪽 포인터 이동
            result = min(result, diff);
            left++;
        }
        if (diff < M) //M 이하면 오른쪽 포인터 이동
            right++;
    }
    return result;
}

int main() {
    int N, M;

    cin >> N >> M;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); //정렬
    cout << minDiff(N, M);
}