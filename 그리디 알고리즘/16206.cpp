#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    vector<int> cake(n);
    for (int i = 0; i < n; i++) {
        cin >> cake[i];
    }

    sort(cake.begin(), cake.end(),
         [](const int &i1, const int &i2) { //둘 다 10으로 나누어떨어지면 짧은 것부터, 아니라면 나누어떨어지는 것 우선
             if (i1 % 10 == 0 && i2 % 10 == 0)
                 return i1 < i2;
             return i1 % 10 == 0;
         });

    int ans = 0;
    for (int i = 0; i < cake.size(); i++) {
        int cut = cake[i] / 10; //자르는 횟수
        if (cake[i] % 10 == 0)
            cut--;
        if (cut <= m) { //다 자를 수 있음
            m -= cut;
            ans += cake[i] / 10;
        } else { //다 못자름
            ans += m;
            break;
        }
    }
    cout << ans;
}