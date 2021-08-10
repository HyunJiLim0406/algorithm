#include <iostream>
#include <vector>

using namespace std;

struct info {
    int x, y, R;
};

vector<int> parent;

bool isConnected(int x1, int y1, int r1, int x2, int y2, int r2) {
    int xd = abs(x1 - x2), yd = abs(y1 - y2), rd = r1 + r2;
    return xd * xd + yd * yd <= rd * rd;
}

int findParent(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return;
    if (parent[xp] < parent[yp]) {
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

    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        parent.assign(N, -1);
        vector<info> input(N);
        for (int i = 0; i < N; i++) //입력
            cin >> input[i].x >> input[i].y >> input[i].R;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isConnected(input[i].x, input[i].y, input[i].R, input[j].x, input[j].y, input[j].R)) //닿아있는지 확인
                    unionInput(i, j); //유니온
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) { //root인 노드의 개수
            if (parent[i] < 0)
                cnt++;
        }
        cout << cnt << '\n';
    }
}