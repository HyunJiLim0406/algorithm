#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    int N;
    ll input;
    map<ll, int> m;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (m[input])
            m[input] += 1;
        else
            m[input] = 1;
    }
    int max_cnt = 0;
    ll max_idx;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > max_cnt) {
            max_cnt = iter->second;
            max_idx = iter->first;
        }
    }
    cout << max_idx;
}