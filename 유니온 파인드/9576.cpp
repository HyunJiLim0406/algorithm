#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) { //b->a 오름차순 정렬
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int findParent(int node) {
    if (parent[node] < 0) //root 노드
        return node;
    return parent[node] = findParent(parent[node]); //부모 갱신하며 root 찾기
}

int main() {
    int T, N, M;

    cin >> T;
    while (T--) {
        cin >> N >> M;

        parent.assign(N + 2, -1);
        vector<pair<int, int>> student(M);
        for (int i = 0; i < M; i++)
            cin >> student[i].first >> student[i].second;
        sort(student.begin(), student.end(), cmp); //정렬

        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int p = findParent(student[i].first); //a의 부모 노드
            if (p <= student[i].second) { //b 이하라면 = 원하는 범위에서 나눠줄 책이 있다면
                cnt++;
                parent[p] = p + 1; //부모 설정
            }
        }
        cout << cnt << '\n';
    }
}