#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6;

vector<int> parent;

int findParent(int node) { //파인드
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { //유니온
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return;
    if (xp < yp) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    char cmd;

    parent.assign(MAX + 1, -1);
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 'I') {
            cin >> a >> b;
            unionInput(a, b);
        }
        if (cmd == 'Q') {
            cin >> a;
            int p = findParent(a);
            cout << abs(parent[p]) << '\n';
        }
    }
}