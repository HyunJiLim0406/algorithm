#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[9], sum = 0;
    int wrong[2]; //잘못 온 난쟁이

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i]; //난쟁이의 키 총합
    }

    sort(arr, arr + 9); //정렬
    sum -= 100; //잘못 온 난쟁이들의 키의 합
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((arr[i] + arr[j]) == sum) { //잘못 온 난쟁이의 쌍 찾기
                wrong[0] = arr[i];
                wrong[1] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) { //출력
        if ((arr[i] != wrong[0]) && (arr[i] != wrong[1]))
            cout << arr[i] << '\n';
    }
}