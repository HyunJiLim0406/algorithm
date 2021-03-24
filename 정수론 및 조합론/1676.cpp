#include <iostream>
#include <algorithm>
using namespace std;

int fact(int N) {
    int two_cnt = 0, five_cnt = 0;

    for (int i = 1; i <= N; i++) {
        int temp = i;
        while (temp % 2 == 0) { //소인수분해로 2가 나오거나
            two_cnt++;
            temp /= 2;
        }
        while (temp % 5 == 0) { //소인수분해로 5가 나오거나
            five_cnt++;
            temp /= 5;
        }
    }
    return min(two_cnt, five_cnt); //2와 5가 모여야 한 쌍이므로 둘 중 작은 수로
}

int main() {
    int N;

    cin >> N;
    cout << fact(N);
}