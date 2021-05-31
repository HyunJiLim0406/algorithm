#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

bool isPromise(int num, int M) {
    int min_num = 10001, max_num = 0, cnt = 1;
    for (int i = 0; i < arr.size(); i++) {
        min_num = min(min_num, arr[i]); //최솟값 갱신
        max_num = max(max_num, arr[i]); //최댓값 갱신
        if (max_num - min_num > num) { //새로운 구간 만들어야 함
            cnt++;
            min_num = arr[i];
            max_num = arr[i];
        }
        if (cnt > M) //최대 구간 넘어감
            return false;
    }
    return true;
}

int lowerSearch(int left, int right, int M) { //lower-bound
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!isPromise(mid, M))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1;
}

int main() {
    int N, M;
    int min_arr = 10001, max_arr = 0;

    cin >> N >> M;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        min_arr = min(min_arr, arr[i]);
        max_arr = max(max_arr, arr[i]);
    }
    cout << lowerSearch(0, max_arr - min_arr, M);
}