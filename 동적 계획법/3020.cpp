#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;

    cin >> N >> H;
    vector<int> ground(N / 2);
    vector<int> sky(N / 2);
    for (int i = 0; i < N / 2; i++)
        cin >> ground[i] >> sky[i];
    sort(ground.begin(), ground.end());
    sort(sky.begin(), sky.end());

    int broken_cnt = N + 1, cnt = 0;
    for (int i = 0; i < H; i++) {
        int tmp = (N / 2) - (upper_bound(ground.begin(), ground.end(), i) - ground.begin()); //부딪히는 석순
        tmp += (N / 2) - (upper_bound(sky.begin(), sky.end(), H - i - 1) - sky.begin()); //부딪히는 종유석
        if (tmp == broken_cnt) //최솟값과 같음
            cnt++;
        else if (tmp < broken_cnt) { //최솟값 갱신
            broken_cnt = tmp;
            cnt = 1;
        }
    }
    cout << broken_cnt << ' ' << cnt;
}