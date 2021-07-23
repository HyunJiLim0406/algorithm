#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, L, x, y, cnt = 0;

    cin >> M >> N >> L;
    vector<int> hunter(M);
    for (int i = 0; i < M; i++)
        cin >> hunter[i];
    sort(hunter.begin(), hunter.end());
    while (N--) {
        cin >> x >> y;

        int num = L - y; //사정거리에서 y값을 뺌
        if (upper_bound(hunter.begin(), hunter.end(), x + num) - lower_bound(hunter.begin(), hunter.end(), x - num) > 0)
            cnt++;
    }
    cout << cnt;
}