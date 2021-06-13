#include <iostream>

using namespace std;

int main() {
    int N, M, package_input, input;
    int package_cost = 1001, cost = 1001; //최소 패키지, 단품 가격

    cin >> N >> M;
    while (M--) {
        cin >> package_input >> input;
        package_cost = min(package_cost, package_input);
        cost = min(cost, input);
    }
    int money = 0;
    if (cost * 6 <= package_cost) //단품 6개가 패키지보다 저렴
        money = cost * N;
    else {
        money += (N / 6) * package_cost; //패키지로 살 수 있는 최대
        N %= 6; //나머지
        if (cost * N <= package_cost) //단품으로 사는게 좋은지 패키지로 하나 더 사는게 좋은지 비교
            money += cost * N;
        else
            money += package_cost;
    }
    cout << money;
}