#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int c, n, s;
};

int main() {
    int n;

    cin >> n;
    vector<int> cnt(n, 0);
    vector<info> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].c >> arr[i].n >> arr[i].s;

    sort(arr.begin(), arr.end(), [](const info &i1, const info &i2) { //점수 기준 정렬
        return i1.s > i2.s;
    });

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 3) //3명 수상
            break;
        if (cnt[arr[i].c] < 2) { //이 국가에서 메달을 받은 아이가 2명 미만인가
            cnt[arr[i].c]++;
            cout << arr[i].c << ' ' << arr[i].n << '\n';
            count++;
        }
    }
}