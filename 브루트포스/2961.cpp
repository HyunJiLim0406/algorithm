#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, result = 1e9 + 1;

    cin >> N;
    vector<pair<int, int>> ingredients(N);
    for (int i = 0; i < N; i++)
        cin >> ingredients[i].first >> ingredients[i].second;
    for (int i = 1; i < (1 << N); i++) { //비트마스킹으로 모든 경우 확인
        int sour = 1, bitter = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sour *= ingredients[j].first; //신맛
                bitter += ingredients[j].second; //쓴맛
            }
        }
        result = min(result, abs(sour - bitter)); //최솟값 갱신
    }
    cout<<result;
}