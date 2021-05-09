#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int x) { //parent[x]가 음수가 될 때까지(root에 다다를 때까지) 재귀 함수 호출
    if (parent[x] < 0)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool unionInput(int x, int y) { //부모가 같으면 cycle 이라는 것
    int x_p = findParent(x); //x의 부모
    int y_p = findParent(y); //y의 부모

    if (x_p == y_p) //이미 같은 집합
        return true;
    if (parent[x_p] < parent[y_p]) { //x_p를 root로 하는 노드가 더 많으면 x_p -> y_p
        parent[x_p] += parent[y_p];
        parent[y_p] = x_p;
    } else { //y_p를 root로 하는 노드가 더 많으면 y_p -> x_p
        parent[y_p] += parent[x_p];
        parent[x_p] = y_p;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y;

    cin >> n >> m;
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        bool is_cycle = unionInput(x, y);
        if (is_cycle) { //사이클이 형성됨 = x와 y의 부모가 같음
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}