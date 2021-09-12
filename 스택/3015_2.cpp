#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, input;
    long long ans = 0;
    stack<pair<int, int>> s; //키, 중복 횟수

    cin >> n;
    while (n--) {
        cin >> input;
        int cnt = 1;
        while (!s.empty()) {
            if (s.top().first < input) { //top이 더 작다면 pop
                ans += s.top().second;
                s.pop();
            } else if (s.top().first == input) { //top과 같다면 갱신
                ans += s.top().second;
                cnt += s.top().second;
                s.pop();
            } else {
                ans++;
                break;
            }
        }
        s.push(make_pair(input, cnt));
    }
    cout << ans;
}