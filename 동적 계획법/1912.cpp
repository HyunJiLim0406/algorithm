#include <iostream>
using namespace std;

int main() { //배열쓰면 시간초과될듯?
    int max = -1001, current_sum = 0;
    int input, n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (current_sum + input >= 0) {
            current_sum += input;
            if (current_sum > max) //지금까지의 연속합이 최댓값보다 크면 갱신
                max = current_sum;
        }
        else {
            current_sum = 0; //이번 입력을 더하면 음수가 되는 경우 연속 끊음
            if (input > max) //근데 전부 음수인 경우가 있을 수 있음
                max = input;
        }
    }
    cout << max;
}