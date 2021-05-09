#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> m; //map을 사용해서 각 이름을 int처럼 사용
vector<int> parent;

int findParent(int x) { //parent[x]가 음수가 될 때까지(root에 다다를 때까지) 재귀 함수 호출
    if (parent[x] < 0)
        return x;
    return parent[x] = findParent(parent[x]);
}

int unionInput(int x, int y) { //union 한 뒤, 집합의 크기 리턴
    int x_p = findParent(x); //x의 부모
    int y_p = findParent(y); //y의 부모

    if (x_p == y_p) //이미 같은 집합
        return parent[x_p];
    if (parent[x_p] < parent[y_p]) { //x_p를 root로 하는 노드가 더 많으면 x_p -> y_p
        parent[x_p] += parent[y_p];
        parent[y_p] = x_p;
        return parent[x_p];
    } else { //y_p를 root로 하는 노드가 더 많으면 y_p -> x_p
        parent[y_p] += parent[x_p];
        parent[x_p] = y_p;
        return parent[y_p];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, F;
    string input[2];

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> F;
        parent.assign(2 * F + 1, -1); //F에 대해 들어올 수 있는 최대 인원 수
        int cnt = 1; //이름에 대한 인덱스
        for (int j = 0; j < F; j++) {
            cin >> input[0] >> input[1];
            for (int k = 0; k < 2; k++) { //map에 없으면 인덱스 추가
                if (m[input[k]] == 0)
                    m[input[k]] = cnt++;
            }
            cout << abs(unionInput(m[input[0]], m[input[1]])) << '\n'; //유니온 연산 후 집합의 크기 출력
        }
        m.clear(); //map 초기화
    }
}