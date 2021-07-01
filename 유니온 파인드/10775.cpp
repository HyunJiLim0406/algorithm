#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int pos) {
    if (parent[pos] == -1) //도킹 가능
        return pos;
    return parent[pos] = findParent(parent[pos]); //부모 갱신
}

bool findPos(int pos) {
    int docking = findParent(pos); //도킹 가능한 게이트
    if (docking == 0) //도킹 불가
        return false;
    parent[docking] = docking - 1; //도킹 처리
    return true;
}

int main() {
    int G, P, gi;

    cin >> G >> P;
    parent.assign(G + 1, -1);
    for (int i = 0; i < P; i++) {
        cin >> gi;
        if (!findPos(gi)) { //도킹 불가능
            cout << i;
            return 0;
        }
    }
    cout << P;
}