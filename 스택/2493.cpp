#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    stack<int> s;

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) { //스택의 맨 윗값이 이번 입력보다 작으면 수신 가능
            arr[s.top()] = i + 1;
            s.pop();
        }
        s.push(i); //이번 입력 투입
    }
    while (!s.empty()) { //수신 불가능한 탑
        arr[s.top()] = 0;
        s.pop();
    }
    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
}