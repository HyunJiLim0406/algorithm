#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, result = 0, x, y;

    cin >> N;
    vector<vector<bool>> paper(101, vector<bool>(101, false));
    while (N--) {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (!paper[i][j]) { //색종이 배치
                    paper[i][j] = true;
                    result++;
                }
            }
        }
    }
    cout << result;
}