#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(5);
    for (int i = 0; i < 5; i++)
        cin >> arr[i];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //바꾸기
                for (int k = 0; k < 5; k++) //출력
                    cout << arr[k] << ' ';
                cout << '\n';
            }
        }
    }
}