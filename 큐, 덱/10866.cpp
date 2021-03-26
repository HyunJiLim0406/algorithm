#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    deque <int> dq;
    int N, num;
    string input;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.compare("push_front") == 0) {
            cin >> num;
            dq.push_front(num);
        }
        else if (input.compare("push_back") == 0) {
            cin >> num;
            dq.push_back(num);
        }
        else if (input.compare("pop_front") == 0) {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                num = dq.front();
                cout << num << '\n';
                dq.pop_front();
            }
        }
        else if (input.compare("pop_back") == 0) {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                num = dq.back();
                cout << num << '\n';
                dq.pop_back();
            }
        }
        else if (input.compare("size") == 0)
            cout << dq.size() << '\n';
        else if (input.compare("empty") == 0)
            cout << dq.empty() << '\n';
        else if (input.compare("front") == 0) {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                num = dq.front();
                cout << num << '\n';
            }
        }
        else if (input.compare("back") == 0) {
            if (dq.empty())
                cout << -1 << '\n';
            else {
                num = dq.back();
                cout << num << '\n';
            }
        }
    }
}