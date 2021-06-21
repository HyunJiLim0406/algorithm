#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K;
struct info { //국가번호, 금메달, 은메달, 동메달
    int num, g, s, b;
};

bool cmp(info &i1, info &i2) { //정렬
    if (i1.g != i2.g)
        return i1.g > i2.g;
    if (i1.s != i2.s)
        return i1.s > i2.s;
    if (i1.b != i2.b)
        return i1.b > i2.b;
    return i1.num == K; //K번 국가가 앞에 오도록
}

int main() {
    int N, num, g, s, b;

    cin >> N >> K;
    vector<info> country(N);
    for (int i = 0; i < N; i++) {
        cin >> num >> g >> s >> b;
        country[i] = {num, g, s, b};
    }

    sort(country.begin(), country.end(), cmp);
    for (int i = 0; i < N; i++) {
        if (country[i].num == K) {
            cout << i + 1;
            break;
        }
    }
}