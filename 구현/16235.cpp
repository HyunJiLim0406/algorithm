#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<vector<int>> soil;
deque<tp> dq;
queue<tp> dead_tree, breeding_tree;

void spring() {
    int size = dq.size();
    while (size--) {
        int age = get<0>(dq.front()); //나이
        int r = get<1>(dq.front()); //행
        int c = get<2>(dq.front()); //열

        if (soil[r][c] >= age) { //먹을 양분이 있으면
            soil[r][c] -= age;
            dq.emplace_back(age + 1, r, c);
            if ((age + 1) % 5 == 0) //나이가 5의 배수면
                breeding_tree.push(make_tuple(age, r, c));
        } else //먹을 양분이 없으면
            dead_tree.push(dq.front());
        dq.pop_front();
    }
}

void summer() {
    while (!dead_tree.empty()) {
        int age = get<0>(dead_tree.front()); //나이
        int r = get<1>(dead_tree.front()); //행
        int c = get<2>(dead_tree.front()); //열
        dead_tree.pop();

        soil[r][c] += (age / 2); //양분 증가
    }
}

void autumn(int N) {
    while (!breeding_tree.empty()) {
        int r = get<1>(breeding_tree.front()); //행
        int c = get<2>(breeding_tree.front()); //열
        breeding_tree.pop();

        for (int i = r - 1; i <= r + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if ((i == r && j == c) || i < 0 || i >= N || j < 0 || j >= N) //범위 내에 있거나 8방향인지 확인
                    continue;
                dq.push_front(make_tuple(1, i, j)); //제일 어린 나무니까 앞에 투입
            }
        }
    }
}

void winter(vector<vector<int>> board, int N) { //양분 추가
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            soil[i][j] += board[i][j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, x, y, z;
    cin >> N >> M >> K;
    vector<vector<int>> board(N, vector<int>(N));
    vector<tp> tree(M); //입력으로 주어지는 나무 정보
    soil.assign(N, vector<int>(N, 5));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree[i] = make_tuple(z, x - 1, y - 1);
    }
    sort(tree.begin(), tree.end()); //초기 정렬
    for (int i = 0; i < M; i++) //덱에 투입
        dq.push_back(tree[i]);
    while (K--) { //봄, 여름, 가을 겨울
        spring();
        summer();
        autumn(N);
        winter(board, N);
    }
    cout << dq.size(); //덱의 크기
}