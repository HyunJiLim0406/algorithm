#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long input;
    vector<long long> arr, sort_arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input); //원래 배열
    }
    sort_arr = arr;
    sort(sort_arr.begin(), sort_arr.end()); //정렬
    sort_arr.erase(unique(sort_arr.begin(), sort_arr.end()), sort_arr.end()); //중복 제거
    for (int i = 0; i < N; i++) //lower bound의 index 반환
        cout << lower_bound(sort_arr.begin(), sort_arr.end(), arr[i]) - sort_arr.begin() << ' ';
}