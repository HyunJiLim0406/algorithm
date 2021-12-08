#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;

    cin >> n >> l;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h.begin(), h.end()); //정렬

    for (int i = 0; i < n; i++) {
        if (h[i] > l) //먹을 수 없는 과일
            break;
        l++;
    }
    cout << l;
}