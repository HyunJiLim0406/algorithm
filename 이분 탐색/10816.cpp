#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cards;

int lowerSearch(int target, int left, int right) { //해당 수가 처음으로 등장하는 위치
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target <= cards[mid]) //왼쪽 탐색
            right = mid - 1;
        else if (target > cards[mid]) //오른쪽 탐색
            left = mid + 1;
    }
    return right + 1;
}

int upperSearch(int target, int left, int right) { //해당 수가 마지막으로 등장하는 위치
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target < cards[mid]) //왼쪽 탐색
            right = mid - 1;
        else if (target >= cards[mid]) //오른쪽 탐색
            left = mid + 1;
    }
    return right + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, input, target;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        cards.push_back(input);
    }
    sort(cards.begin(), cards.end()); //정렬

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> target;
        cout << upperSearch(target, 0, cards.size() - 1) - lowerSearch(target, 0, cards.size() - 1) << ' ';
    }
}