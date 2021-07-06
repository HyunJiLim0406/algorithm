#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int max_num = -1001, sum = 0, del_sum = 0;
    int input, n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        del_sum = max(sum, del_sum+input); //이번 input 제거 or 사용
        if (sum + input >= 0) {
            sum += input;
            max_num = max(max_num, max(del_sum, sum));
        }
        else {
            sum = 0; //이번 입력을 더하면 음수가 되는 경우 연속 끊음
            max_num = max(max_num, input); //근데 전부 음수인 경우가 있을 수 있음
        }
    }
    cout << max_num;
}