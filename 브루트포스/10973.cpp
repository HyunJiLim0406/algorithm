#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, input;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }
    if (prev_permutation(arr.begin(), arr.end())) { //이전 순열이 있다면
        for (int i = 0; i < N; i++)
            cout << arr[i] << ' ';
    } else //없다면
        cout << -1;
}