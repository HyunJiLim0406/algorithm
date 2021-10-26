#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, score, p;

    cin >> n >> score >> p;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == p && arr[n - 1] >= score) { //못 들어감
        cout << -1;
        return 0;
    }
    int cnt = 1;
    for (int i = 0; i < n; i++) { //나보다 앞에 있는 사람 수
        if (arr[i] > score)
            cnt++;
    }
    cout << cnt;
}