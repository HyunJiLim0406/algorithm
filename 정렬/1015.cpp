#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<pair<int, int>> arr(N);
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first; //값
        arr[i].second = i; //원래 인덱스
    }
    sort(arr.begin(), arr.end()); //값 기준 오름차순 정렬
    for (int i = 0; i < N; i++) //인덱스 보면서 정렬 후 인덱스 삽입
        result[arr[i].second] = i;
    for (int i = 0; i < N; i++)
        cout << result[i] << ' ';
}