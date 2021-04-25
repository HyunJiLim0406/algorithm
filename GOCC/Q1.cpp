#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_num = 100000, N, cur, result;
vector<int> v;

void backtracking(int length, int idx) {
    if (length < min_num) { //non promising
        for (int i = idx + 1; i < v.size(); i++) {
            int saved = cur; //기존 값 기억
            cur |= v[i]; //visited
            if (cur == result) //길이 갱신
                min_num = min(min_num, length + 1);
            backtracking(length + 1, i);
            cur = saved; //unvisited
        }
    }
}

int main() {
    int T, input;

    cin >> T;
    for (int i = 0; i < T; i++) {
        result = 0;
        min_num = 100000;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> input;
            v.push_back(input);
            result |= input; //모든 input의 or 연산
        }
        backtracking(0, -1);
        cout << min_num << '\n';
    }
}