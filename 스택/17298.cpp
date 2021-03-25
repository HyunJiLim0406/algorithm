#include <iostream>
#include <stack>

using namespace std;

int num_arr[1000000];

void oaken(int length) {
    stack<int> temp; //오큰수를 구하지 못한 수의 index를 저장
    temp.push(0);

    for (int i = 1; i < length; i++) {
        while (!temp.empty() && num_arr[i] > num_arr[temp.top()]) { //num_arr[i]가 오큰수가 될 수 있는가?
            num_arr[temp.top()] = num_arr[i];
            temp.pop();
        }
        temp.push(i);
    }
    while (!temp.empty()) { //여전히 스택에 남아있는 수라면 오큰수가 없는 것
        num_arr[temp.top()] = -1;
        temp.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num_arr[i];
    oaken(N);
    for (int i = 0; i < N; i++)
        cout << num_arr[i] << ' ';
}