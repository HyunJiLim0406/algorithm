#include <iostream>

using namespace std;

struct city_info {
    long long dist;
    long long oil;
};

long long min_oil(city_info *c, int length) {
    long long cur_oil = c[0].oil;
    long long money = 0;

    for (int i = 0; i < length; i++) {
        if (c[i].oil < cur_oil) //이번 도시의 기름 가격이 지금 넣고 있던 기름 가격보다 저렴하면 기름 변경
            cur_oil = c[i].oil;
        money += (cur_oil * c[i].dist);
    }
    return money;
}

int main() {
    int N;

    cin >> N;
    city_info *city = new city_info[N];

    for (int i = 0; i < N - 1; i++)
        cin >> city[i].dist;
    city[N - 1].dist = 0;
    for (int i = 0; i < N; i++)
        cin >> city[i].oil;

    cout << min_oil(city, N);
}