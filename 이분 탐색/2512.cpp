#include <iostream>
#include <vector>

using namespace std;

int M;
vector<int> arr;

bool isPromise(int num) {
    int tot = 0;
    for (int & i : arr)
        tot += (i > num) ? num : i;
    return tot <= M;
}

int upperSearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPromise(mid)) //이 예산으로 배졍 가능
            left = mid + 1;
        else //이 예산으로 배정 불가능
            right = mid - 1;
    }
    return right;
}

int main() {
    int N, sum = 0, max_num = 0;

    cin >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max_num = max(max_num, arr[i]); //최댓값 = right
        sum += arr[i]; //요청 예산의 총합
    }
    cin >> M;
    if (sum <= M) //상한액 계산할 필요 없음
        cout << max_num;
    else //upper-bound
        cout << upperSearch(0, max_num);
}