#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, sorted_arr;
long long res;

void merge(int left, int mid, int right) { //병합
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            sorted_arr[k++] = arr[i++];
        else { //순서 뒤집히면 기록
            sorted_arr[k++] = arr[j++];
            res += (j - k);
        }
    }
    while (i <= mid) //왼쪽 배열 남았는지
        sorted_arr[k++] = arr[i++];
    while (j <= right) //오른쪽 배열 남았는지
        sorted_arr[k++] = arr[j++];
    for (int l = left; l <= right; l++) //복사
        arr[l] = sorted_arr[l];
}

void mergeSort(int left, int right) {
    if (left < right) { //분할
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int N;

    cin >> N;
    arr.assign(N, 0);
    sorted_arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    mergeSort(0, N - 1); //병합 정렬
    cout << res;
}