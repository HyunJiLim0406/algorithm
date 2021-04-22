#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

bool isBroken[10];
string N;
int min_click;
deque<int> channel;

void backtracking(int pos, int digit) {
    if (digit == 0) //1 1 1 => 2
        return;
    if (pos == digit) {
        int mul = 1, ch = 0;
        for (int i = 0; i < pos; i++) {
            int num = channel.back();
            ch += (num * mul);
            channel.pop_back();
            channel.push_front(num);
            mul *= 10;
        }
        min_click = min(min_click, abs(stoi(N) - ch) + pos);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!isBroken[i]) {
            channel.push_back(i);
            backtracking(pos + 1, digit);
            channel.pop_back();
        }
    }
}

int main() {
    int M;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;
        isBroken[input] = true;
    }

    min_click = abs(stoi(N) - 100);
    if (M != 10) {
        backtracking(0, N.size() - 1); //11 8 1 3 4 5 6 7 8 9 => 10
        backtracking(0, N.size());
        backtracking(0, N.size() + 1); //999 1 9 => 5
    }
    cout << min_click;
}