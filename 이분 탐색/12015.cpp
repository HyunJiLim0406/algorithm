#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void binaryInsert(int input) { //lower bound
    int left = 0;
    int right = arr.size() - 1;

    if (input > arr[right]) {
        arr.push_back(input);
        return;
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        if (input <= arr[mid]) //왼쪽 탐색
            right = mid - 1;
        else if (input > arr[mid]) //오른쪽 탐색
            left = mid + 1;
    }
    //값을 replace 하는 과정, right+1이 lower bound
    arr.erase(arr.begin() + right + 1);
    arr.insert(arr.begin() + right + 1, input);
    return;
}

int main() {
    int N, input;

    arr.push_back(0); //초기값으로 제일 작은 0 투입
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        binaryInsert(input);
    }
    cout << arr.size() - 1; //0을 미리 넣어 놓았으니까 1 빼야 함
}