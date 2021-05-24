#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> arr;
    vector<bool> is_exist;

    cin >> N;
    arr.assign(N, 0);
    is_exist.assign(2000001, false);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 1; i < (1 << N); i++) { //비트마스크
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (((1 << j) & i) != 0)
                sum += arr[j];
        }
        is_exist[sum] = true; //존재 처리
    }
    for (int i = 1; i < is_exist.size(); i++) {
        if (!is_exist[i]) {
            cout << i;
            return 0;
        }
    }
}