#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, l;

    cin >> t;
    while (t--) {
        cin >> l >> n;
        vector<int> ant(n);
        for (int i = 0; i < n; i++)
            cin >> ant[i];
        int min_t = 0, max_t = 0;
        for (int i = 0; i < n; i++) {
            min_t = max(min_t, min(ant[i], l - ant[i])); //가장 빨리 떨어지는 방법 중 가장 큰 값
            max_t = max(max_t, max(ant[i], l - ant[i])); //가장 느리게 떨어지는 방법 중 가장 큰 값
        }
        cout << min_t << ' ' << max_t << '\n';
    }
}