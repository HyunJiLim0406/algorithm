#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int K, d, len, result1 = 1, result2 = 1;
    vector<int> cnt(4, 0);
    deque<pair<int, int>> input;

    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> d >> len;
        cnt[d - 1]++;
        input.emplace_back(d - 1, len);
    }
    while (cnt[input.front().first] != 1 || cnt[input.back().first] != 2) { //한번만 등장한게 앞에 오도록
        pair<int, int> tmp = input.back();
        input.pop_back();
        input.push_front(tmp);
    }
    for (int i = 0; i < 2; i++) { //큰 사각형
        result1 *= input.front().second;
        input.pop_front();
    }
    input.pop_front();
    for (int i = 0; i < 2; i++) { //작은 사각형
        result2 *= input.front().second;
        input.pop_front();
    }
    cout << (result1 - result2) * K;
}