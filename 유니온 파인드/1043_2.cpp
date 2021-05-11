#include <iostream>
#include <vector>

using namespace std;

vector<bool> isLie; //이 사람에게 거짓말을 할 수 있나?
vector<int> parent; //부모 정보
vector<vector<int>> party_info; //파티 정보

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

int main() { //유니온 파인드 풀이
    int N, M, t, num, input, first;
    vector<int> init;

    cin >> N >> M;
    isLie.assign(N + 1, true);
    parent.assign(N + 1, -1);
    party_info.assign(M, vector<int>(0));

    cin >> t;
    init.assign(t, 0);
    for (int i = 0; i < t; i++) { //처음에 주어진 진실을 아는 사람
        cin >> init[i];
        isLie[init[i]] = false;
    }
    for (int i = 0; i < M; i++) {
        cin >> num >> first;
        party_info[i].push_back(first); //각 파티의 첫번째 원소
        for (int j = 0; j < num - 1; j++) { //입력 받으면서 유니온
            cin >> input;
            party_info[i].push_back(input);
            unionInput(first, input);
        }
    }
    for (int i = 0; i < init.size(); i++) { //isLie 갱신
        int mark = findParent(init[i]); //isLie가 false인 사람의 부모
        for (int j = 1; j < parent.size(); j++) { //부모가 같다면 false 처리
            if (findParent(j) == mark)
                isLie[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) { //파티 정보의 첫번째 사람만 체크해도 됨
        if (isLie[party_info[i][0]])
            cnt++;
    }
    cout << cnt;
}