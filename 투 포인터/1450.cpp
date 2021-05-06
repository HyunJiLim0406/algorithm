#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> arr;

vector<ll> splitArr(int left, int len) {
    vector<ll> result;
    for (int i = 0; i < (1 << len); i++) {
        ll sum = 0;
        for (int j = 0; j < len; j++) {
            if (((1 << j) & i) != 0)
                sum += arr[left + j];
        }
        result.push_back(sum);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C, result = 0;

    cin >> N >> C;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<ll> front_arr = splitArr(0, N / 2);
    vector<ll> back_arr;
    if (N % 2 == 0)
        back_arr = splitArr(N / 2, N / 2);
    else
        back_arr = splitArr(N / 2, N / 2 + 1);
    sort(back_arr.begin(), back_arr.end());
    for (int i = 0; i < front_arr.size(); i++) {
        result += upper_bound(back_arr.begin(), back_arr.end(), C - front_arr[i]) - back_arr.begin();
    }
    cout << result;
}