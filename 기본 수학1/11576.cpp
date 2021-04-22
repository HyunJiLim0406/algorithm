#include <iostream>
#include <stack>

using namespace std;

int main() {
    int A, B, m;
    int arr[25];
    stack<int> s;

    cin >> A >> B >> m;
    for (int i = m - 1; i >= 0; i--)
        cin >> arr[i];
    int ten_num = 0;
    int mul = 1;
    for (int i = 0; i < m; i++) { //10진법으로
        ten_num += (arr[i] * mul);
        mul *= A;
    }
    while (ten_num != 0) { //B진법으로
        s.push(ten_num % B);
        ten_num /= B;
    }
    while (!s.empty()) { //출력
        cout << s.top() << ' ';
        s.pop();
    }
}