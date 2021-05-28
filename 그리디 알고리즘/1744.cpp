#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedySum(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) { //인접한 두 수를 곱하는 것이 더하는 것보다 나은지 확인
        if ((i + 1 < arr.size()) && ((arr[i] * arr[i + 1]) > (arr[i] + arr[i + 1]))) {
            sum += (arr[i] * arr[i + 1]);
            i++;
        } else
            sum += arr[i];
    }
    return sum;
}

int main() {
    int N, input;
    vector<int> arr1, arr2;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input > 0) //양수
            arr1.push_back(input);
        else //음수, 0
            arr2.push_back(input);
    }
    sort(arr1.begin(), arr1.end(), greater<>()); //내림차순 정렬
    sort(arr2.begin(), arr2.end()); //오름차순 정렬

    cout << greedySum(arr1) + greedySum(arr2);
}