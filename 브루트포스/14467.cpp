#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, ans = 0;
    vector<int> cow(11, -1);

    cin >> n;
    while (n--) {
        cin >> a >> b;

        if (cow[a] != -1 && cow[a] != b) //이동 확인
            ans++;
        cow[a] = b; //위치 갱신
    }
    cout << ans;
}