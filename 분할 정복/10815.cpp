#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    vector<int> input, output;

    cin >> N;
    input.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    cin >> M;
    output.assign(M, 0);
    for (int i = 0; i < M; i++)
        cin >> output[i];
    sort(input.begin(), input.end());
    for (int i = 0; i < M; i++)
        cout << binary_search(input.begin(), input.end(), output[i])<<' ';
}