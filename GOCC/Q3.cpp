#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T, N, q, first, second;

    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> v;
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> first;
            v.push_back(first);
        }
        cin >> q;
        for (int j = 0; j < q; j++) {
            int max_num = 0, target;
            bool isFound = false;
            cin >> first >> second;
            for (int k = 0; k < N; k++) {
                if ((v[k] < second) && ((first ^ v[k]) > max_num)) { //second보다 작으면서 xor 연산시 최댓값이 되는 v[k]
                    max_num = first ^ v[k];
                    target = v[k];
                    isFound = true;
                }
            }
            if (!isFound)
                cout << -1 << '\n';
            else
                cout << target << '\n';
        }
    }
}