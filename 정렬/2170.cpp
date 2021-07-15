#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, len = 0;

    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end()); //정렬
    int s = arr[0].first, e = arr[0].second; //초깃값
    for (int i = 1; i < N; i++) {
        if (arr[i].first > e) { //펜을 떼야 함
            len += (e - s);
            s = arr[i].first;
            e = arr[i].second;
        }
        e = max(e, arr[i].second); //계속 잇기
    }
    len += (e - s);
    cout << len;
}