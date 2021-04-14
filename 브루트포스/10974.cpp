#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }

    do { //순서대로 출력
       for (int i = 0; i < N; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    } while (next_permutation(arr.begin(), arr.end()));
}