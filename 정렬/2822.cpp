#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int input, sum = 0;
    vector<pair<int, int>> scores(8);
    set<int> idx;

    for (int i = 0; i < 8; i++) {
        cin >> input;
        scores[i] = make_pair(input, i);
    }
    sort(scores.begin(), scores.end(), greater<>()); //내림차순 정렬
    for (int i = 0; i < 5; i++) {
        sum += scores[i].first; //합
        idx.insert(scores[i].second + 1); //인덱스 오름차순
    }
    cout << sum << '\n';
    for (auto iter:idx)
        cout << iter << ' ';
}