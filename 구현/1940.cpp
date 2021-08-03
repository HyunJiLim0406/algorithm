#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, result = 0;

    cin >> N >> M;
    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (input[i] + input[j] == M)
                result++;
        }
    }
    cout << result;
}