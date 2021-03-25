#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void isStack(vector<int> arr) {
    int index = 1;
    stack<int> s;
    vector<char> pm;

    for (int i = 0; i < arr.size(); i++) {
        while (index <= arr[i]) { //arr[i]가 index보다 크거나 같으면 일단 push
            s.push(index);
            pm.push_back('+');
            index++;
        }
        if (!s.empty() && arr[i] == s.top()) { //empty 체크 중요함. 더 이상 push 못하는 상황에서 pop 가능한지 확인
            s.pop();
            pm.push_back('-');
        } else { //불가능하면 수열 만들 수 없음
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < pm.size(); i++)
        cout << pm[i] << '\n';
}

int main() {
    vector<int> arr;
    int n, input;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr.push_back(input);
    }
    isStack(arr);
}