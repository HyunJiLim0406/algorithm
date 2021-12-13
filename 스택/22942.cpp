#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct info {
    int p, n;
    bool left;
};

bool promising(vector<info> &pos) {
    stack<int> s;
    s.push(pos[0].n);
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i - 1].p == pos[i].p) //위치가 같음
            return false;
        if (pos[i].left) //왼쪽 원
            s.push(pos[i].n);
        else { //오른쪽 원
            if (s.top() != pos[i].n) //겹칠 때
                return false;
            s.pop();
        }
    }
    return true;
}

int main() {
    int n, x, r;

    cin >> n;
    vector<info> pos;
    for (int i = 0; i < n; i++) {
        cin >> x >> r;
        pos.push_back({x - r, i, true}); //왼쪽 원
        pos.push_back({x + r, i, false}); //오른쪽 원
    }

    sort(pos.begin(), pos.end(), [](const info &i1, const info &i2) { //위치 기준 정렬
        return i1.p < i2.p;
    });

    cout << (promising(pos) ? "YES" : "NO");
}