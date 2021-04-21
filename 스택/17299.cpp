#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int arr[1000000][2], f[1000001], N;

void rab() {
    stack<int> s;

    for (int i = 0; i < N; i++) {
        while ((!s.empty()) && (f[arr[s.top()][0]] < f[arr[i][0]])) { //오등큰수를 찾음
            arr[s.top()][1] = arr[i][0];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) { //오등큰수를 못찾음
        arr[s.top()][1] = -1;
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0];
        f[arr[i][0]]++;
    }
    rab(); //오등큰
    for (int i = 0; i < N; i++) //출력
       cout << arr[i][1] << ' ';
}