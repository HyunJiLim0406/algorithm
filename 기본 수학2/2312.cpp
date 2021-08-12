#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> factorization(int N) {
    vector<pair<int, int>> result;
    int mod = 2;
    while (N != 1) {
        int cnt = 0;
        while (N % mod == 0) {
            N /= mod;
            cnt++;
        }
        if (cnt)
            result.emplace_back(mod, cnt);
        mod++;
    }
    return result;
}

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        vector<pair<int, int>> result = factorization(N);
        for(auto & item : result)
            cout << item.first << ' ' << item.second << '\n';
    }
}