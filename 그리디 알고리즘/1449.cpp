#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, L;

    cin >> N >> L;
    vector<int> hole(N);
    for (int i = 0; i < N; i++)
        cin >> hole[i];
    sort(hole.begin(), hole.end()); //정렬

    int cnt = 0, cur = -1001;
    for (int i = 0; i < N; i++) {
        if (hole[i] - cur >= L) { //새로운 테이프를 사용해야 함
            cnt++;
            cur = hole[i];
        }
    }
    cout << cnt;
}