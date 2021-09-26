#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] < arr[i + 1] + arr[i + 2]) { //삼각형이 될 수 있는 가장 큰 수의 조합
            cout << arr[i] + arr[i + 1] + arr[i + 2];
            return 0;
        }
    }
    cout << -1;
}