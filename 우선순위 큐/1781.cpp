#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int main() {
    int n, a, b;
    priority_queue<ci> input;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        input.push({a, b}); //데드라인이 넉넉한 순
    }

    int ans = 0;
    priority_queue<int> tmp;
    while (n) {
        while (!input.empty() && input.top().first >= n) { //이 데드라인까지 할 수 있는 과제
            tmp.push(input.top().second);
            input.pop();
        }
        if (!tmp.empty()) { //가장 컵라면을 많이 받을 수 있는 과제 수행
            ans += tmp.top();
            tmp.pop();
        }
        n--;
    }
    cout << ans;
}