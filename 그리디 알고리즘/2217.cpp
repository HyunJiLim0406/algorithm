#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, result = 0;

    cin >> N;
    vector<int> rope(N);
    for (int i = 0; i < N; i++)
        cin >> rope[i];
    sort(rope.begin(), rope.end(), greater<>()); //정렬
    for (int i = 0; i < N; i++)
        result = max(result, rope[i] * (i + 1)); //이번 로프를 쓸지 말지
    cout << result;
}