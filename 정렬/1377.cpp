#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, input;
    vector<pair<int, int>> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.emplace_back(input, i);
    }
    sort(arr.begin(), arr.end()); //정렬

    int max_dist = 0;
    for (int i = 0; i < N; i++) //원래 인덱스와 비교해서 얼마나 이동했는지 확인
        max_dist = max(max_dist, arr[i].second - i);
    cout << max_dist + 1;
}