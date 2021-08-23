#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

struct info {
    int idx, color, weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, c, w, sum = 0;

    cin >> N;
    vector<info> ball(N);
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        cin >> c >> w;
        ball[i] = {i, c, w};
    }
    sort(ball.begin(), ball.end(), //무게 순으로 정렬
         [](const info &i1, const info &i2) {
             return i1.weight < i2.weight;
         });
    for (int i = 0; i < N; i++) {
        int cur_weight = ball[i].weight, j;
        for (j = i; j < N; j++) { //같은 무게의 공 한번에 처리
            if (ball[j].weight != cur_weight)
                break;
            result[ball[j].idx] = sum - m[ball[j].color];
        }
        for (int k = i; k < j; k++) { //누적합 갱신
            sum += ball[k].weight;
            m[ball[k].color] += ball[k].weight;
        }
        i = j - 1; //i값 갱신
    }
    for (int i = 0; i < N; i++)
        cout << result[i] << '\n';
}