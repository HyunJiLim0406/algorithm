#include <iostream>

using namespace std;

int main() {
    int n, k, ans = 0;
    string input;

    cin >> n >> k >> input;
    for (int i = 0; i < n; i++) {
        if (input[i] != 'P') //사람이 없음
            continue;
        for (int j = max(0, i - k); j < min(n, i + k+1); j++) { //가장 가까운 햄버거
            if (input[j] == 'H') {
                ans++;
                input[j] = '.';
                break;
            }
        }
    }
    cout << ans;
}