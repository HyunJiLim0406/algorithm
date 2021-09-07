#include <iostream>

using namespace std;

int cntNum(int num1, int num2) {
    int cnt = 2;
    while (num1 - num2 >= 0) {
        int tmp = num1 - num2;
        num1 = num2;
        num2 = tmp;
        cnt++;
    }
    return cnt;
}

int main() {
    int n, max_cnt = 0, max_num;

    cin >> n;
    for (int i = n / 2; i <= n; i++) {
        int size = cntNum(n, i);
        if (size > max_cnt) {
            max_cnt = size;
            max_num = i;
        }
    }
    cout << max_cnt << '\n' << n << ' '<<max_num<<' ';
    while (n - max_num >= 0) {
        int tmp = n - max_num;
        n = max_num;
        max_num = tmp;
        cout << max_num << ' ';
    }
}