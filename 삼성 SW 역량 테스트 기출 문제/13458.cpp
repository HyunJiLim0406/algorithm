#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, B, C;
    long long cnt = 0;
    vector<int> num;

    cin >> N;
    num.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> num[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++) {
        cnt++;
        num[i] -= B;
        if (num[i] > 0) {
            if (num[i] % C == 0)
                cnt += (num[i] / C);
            else
                cnt += (num[i] / C + 1);
        }
    }
    cout << cnt;
}