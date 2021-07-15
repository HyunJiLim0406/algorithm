#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N, P, a, b, cnt = 0;

    cin >> N >> P;
    vector<stack<int>> guitar(7);
    while (N--) {
        cin >> a >> b;
        while (!guitar[a].empty() && guitar[a].top() > b) { //손을 떼야 함
            cnt++;
            guitar[a].pop();
        }
        if (guitar[a].empty() || guitar[a].top() != b) { //프랫을 눌러야 함
            cnt++;
            guitar[a].push(b);
        }
    }
    cout << cnt;
}