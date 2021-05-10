#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    map<string, bool> never_heard, never_seen;
    map<string, bool>::iterator m_iter;
    set<string> result;
    set<string>::iterator s_iter;
    string input;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        never_heard[input] = true;
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        never_seen[input] = true;
    }
    for (m_iter = never_heard.begin(); m_iter != never_heard.end(); m_iter++) { //공통되는 이름 set에 넣기
        if (never_seen[m_iter->first])
            result.insert(m_iter->first);
    }
    cout << result.size() << '\n';
    for (s_iter = result.begin(); s_iter != result.end(); s_iter++) //set 출력
        cout << *s_iter << '\n';
}