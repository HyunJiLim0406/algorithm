#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int result = 0;
    string input;
    vector<int> arr(10, 0);

    cin >> input;
    for (int i = 0; i < input.size(); i++) //등장 횟수 갱신
        arr[input[i] - '0']++;
    int divide_num = (arr[6] + arr[9]) / 2; //6, 9는 함께 쓸 수 있음
    arr[6] = (arr[6] + arr[9]) - divide_num;
    arr[9] = divide_num;
    for (int i = 0; i < 10; i++) //최댓값 갱신
        result = max(result, arr[i]);
    cout << result;
}