#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); //오름차순 정렬
    int cur = 0; //초기값
    for (int i = 0; i < N; i++) {
        if (arr[i] > (cur + 1)) //연속된 무게를 만들 수 없음
            break;
        cur += arr[i]; //만들 수 있는 연속된 무게 중 최댓값
    }
    cout << cur + 1;
}