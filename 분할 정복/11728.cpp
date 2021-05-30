#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, input;
    multiset<int> arr;

    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        cin >> input;
        arr.insert(input);
    }
    for (auto iter:arr)
        cout << iter << ' ';
}