#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr(1e5);

void calc(int num, bool flag) {
    int line = sqrt(num);
    for (int i = 2; i <= line; i++) {
        while (num % i == 0) {
            flag ? arr[i]++ : arr[i]--;
            num /= i;
        }
    }
    if (num > 1)
        flag ? arr[num]++ : arr[num]--;
}

bool isMint() {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0)
            return false;
    }
    return true;
}

int main() {
    int N, num;
    char op = '*';

    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i != 0)
            cin >> op;
        cin >> num;
        num = abs(num);
        if (num == 0) {
            cout << "mint chocolate";
            return 0;
        }
        if (op == '*')
            calc(num, true);
        if (op == '/')
            calc(num, false);
    }
    cout << ((isMint()) ? "mint chocolate" : "toothpaste");
}