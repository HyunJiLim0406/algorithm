#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;

    cin >> T;
    while (T--) {
        vector<int> arr(10);
        for (int i = 0; i < 10; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
        cout << arr[2] << '\n'; //3번째로 큰 수
    }
}