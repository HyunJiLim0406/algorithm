#include <iostream>
#include <vector>

using namespace std;

pair<int, int> maxVisitor(int n, int x, vector<int> &visitor) {
    int section_visitor = 0;
    //처음 윈도우
    for (int i = 0; i < x; i++)
        section_visitor += visitor[i];
    int ans = section_visitor;
    int cnt = 1;

    for (int i = x; i < n; i++) {
        section_visitor -= visitor[i - x]; //맨 앞 빼고
        section_visitor += visitor[i]; //맨 뒤 더하고
        if (section_visitor > ans) { //최댓값보다 크다면 갱신
            cnt = 0;
            ans = section_visitor;
        }
        if (section_visitor == ans) //최댓값과 같다면 개수 추가
            cnt++;
    }
    return make_pair(ans, cnt);
}

int main() {
    int n, x;

    cin >> n >> x;
    vector<int> visitor(n, 0);
    for (int i = 0; i < n; i++)
        cin >> visitor[i];

    pair<int, int> ans = maxVisitor(n, x, visitor);
    if (ans.first == 0) {
        cout << "SAD\n";
        return 0;
    }
    cout << ans.first << '\n' << ans.second;
}