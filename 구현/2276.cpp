#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N, M;

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> note1(N);
        for (int i = 0; i < N; i++)
            cin >> note1[i];
        cin >> M;
        vector<int> note2(M);
        for (int i = 0; i < M; i++)
            cin >> note2[i];
        sort(note1.begin(), note1.end()); //정렬
        for (int i = 0; i < M; i++) {
            if (binary_search(note1.begin(), note1.end(), note2[i])) //존재
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}