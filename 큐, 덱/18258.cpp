#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue <int> q;
    int N, num;
    string input;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.compare("push") == 0) {
            cin >> num;
            q.push(num);
        }
        else if (input.compare("pop") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                num = q.front();
                cout << num << '\n';
                q.pop();
            }
        }
        else if (input.compare("size") == 0)
            cout << q.size() << '\n';
        else if (input.compare("empty") == 0)
            cout << q.empty() << '\n';
        else if (input.compare("front") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (input.compare("back") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }
}