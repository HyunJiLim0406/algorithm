#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> factorization(int N) {
    vector<pair<int, int>> result;
    int mod = 2;
    while (N != 1) { //1이 되면 break
        int cnt = 0;
        while (N % mod == 0) { //mod로 나눠 떨어지지 않을 때까지 나누기
            N /= mod;
            cnt++;
        }
        if (cnt) //한번이라도 나뉜 적 있다면
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