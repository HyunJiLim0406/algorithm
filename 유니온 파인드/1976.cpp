#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int x) { //parent[x]가 음수가 될 때까지(root에 다다를 때까지) 재귀 함수 호출
    if (parent[x] < 0)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionInput(int x, int y) {
    int x_p = findParent(x); //x의 부모
    int y_p = findParent(y); //y의 부모

    if (x_p == y_p) //이미 같은 집합
        return;
    if (parent[x_p] < parent[y_p]) { //x_p를 root로 하는 노드가 더 많으면 x_p -> y_p
        parent[x_p] += parent[y_p];
        parent[y_p] = x_p;
    } else { //y_p를 root로 하는 노드가 더 많으면 y_p -> x_p
        parent[y_p] += parent[x_p];
        parent[x_p] = y_p;
    }
}

int main() {
    int N, M, input;

    cin >> N >> M;
    parent.assign(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input;
            if (input == 1) //길이 있다면 union
                unionInput(i, j);
        }
    }
    int p;
    for (int i = 0; i < M; i++) { //여행 가능하려면 모든 input의 parent가 같아야 함
        cin >> input;
        if (i == 0) //parent 초기화
            p = findParent(input);
        else if (p != findParent(input)) { //parent가 다르다면 NO 리턴
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n"; //YES 리턴
}