#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, x1, x2, y1, y2, input;
    vector<vector<int>> b;

    cin >> N >> M;
    b.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) { //가로 누적
        for (int j = 1; j <= N; j++) {
            cin >> input;
            b[i][j] = input + b[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) { //세로 누적
        for (int j = 1; j <= N; j++)
            b[i][j] += b[i - 1][j];
    }
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = b[x2][y2] - b[x2][y1 - 1] - b[x1 - 1][y2] + b[x1 - 1][y1 - 1];
        cout << result << '\n';
    }
}