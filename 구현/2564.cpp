#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, num, p, d, result = 0;

    cin >> N >> M >> num;
    int tot_len = 2 * (N + M);
    vector<int> dist(num + 1);
    for (int i = 0; i <= num; i++) { //왼쪽 위 점으로부터의 거리
        cin >> p >> d;
        if (p == 1)
            dist[i] = d;
        if (p == 2)
            dist[i] = N + M + (N - d);
        if (p == 3)
            dist[i] = tot_len - d;
        if (p == 4)
            dist[i] = N + d;
    }
    for (int i = 0; i < num; i++) {
        int tmp = abs(dist[i] - dist[num]);
        result += min(tmp, tot_len - tmp);
    }
    cout << result;
}