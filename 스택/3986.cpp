#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N, cnt = 0;

    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];
    for (int i = 0; i < N; i++) {
        stack<char> s;
        for (int j = 0; j < words[i].size(); j++) {
            if (s.empty() || s.top() != words[i][j]) //짝이 맞지 않음
                s.push(words[i][j]);
            else //짝이 맞음
                s.pop();
        }
        if (s.empty()) //스택이 비어 있다면
            cnt++;
    }
    cout << cnt;
}