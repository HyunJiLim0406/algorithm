#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        double ans = 1e9;
        cin >> N;
        vector<pair<int, int>> arr(N);
        vector<int> comb(N, 1); //조합용
        for (int i = 0; i < N; i++)
            cin >> arr[i].first >> arr[i].second;
        for (int i = 0; i < N / 2; i++) //절반은 0으로
            comb[i] = 0;
        do {
            pair<int, int> plus = {0, 0}, minus = {0, 0};
            for (int i = 0; i < N; i++) {
                if (comb[i] == 0) { //더하게 될 벡터
                    plus.first += arr[i].first;
                    plus.second += arr[i].second;
                } else { //빼게 될 벡터
                    minus.first += arr[i].first;
                    minus.second += arr[i].second;
                }
            }
            pair<ll, ll> calc = {plus.first - minus.first, plus.second - minus.second}; //벡터의 총합
            ans = min(ans, sqrt(calc.first * calc.first + calc.second * calc.second)); //최솟값 갱신
        } while (next_permutation(comb.begin(), comb.end()));

        cout << fixed;
        cout.precision(12);
        cout << ans << '\n';
    }
}