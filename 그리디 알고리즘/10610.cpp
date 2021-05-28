#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    string input;
    vector<int> arr;

    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        sum += (input[i] - '0');
        arr.push_back(input[i] - '0');
    }
    sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
    if ((arr[arr.size() - 1] != 0) || (sum % 3 != 0)) //10으로 나누어 떨어지지 않거나, 3으로 나누어 떨어지지 않을 때
        cout << -1;
    else { //출력
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i];
    }
}