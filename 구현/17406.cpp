#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct info {
    int idx, r, c, s;
};

vector<vector<int>> matrix;
pair<int, int> dir[4] = {{0,  1},  //우
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {-1, 0}}; //상

void rotate(int sr, int sc, int er, int ec) {
    queue<int> q;
    q.push(matrix[sr][sc]); //시작점 값
    int row = sr, col = sc + 1, d = 0; //시작점의 바로 오른쪽 좌표로 초기화
    do {
        q.push(matrix[row][col]); //값 저장
        matrix[row][col] = q.front(); //이전 위치의 값으로 업데이트
        q.pop();
        row += dir[d].first;
        col += dir[d].second;
        if ((row < sr) || (row > er) || (col < sc) || (col > ec)) { //범위를 벗어나면 위치 조정하고 방향 바꾸기
            row = row - dir[d].first + dir[(d + 1) % 4].first;
            col = col - dir[d].second + dir[(d + 1) % 4].second;
            d = (d + 1) % 4;
        }
    } while (row != sr || col != sc + 1); //원위치로 돌아올 때까지
}

int calcArr(int N, int M) { //배열의 값
    int result = 5001, tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) //행의 합
            tmp += matrix[i][j];
        result = min(result, tmp); //최솟값 갱신
        tmp = 0;
    }
    return result;
}

int main() {
    int N, M, K, result = 5001;

    cin >> N >> M >> K;
    matrix.assign(N, vector<int>(M));
    vector<info> rot(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];
    }
    for (int i = 0; i < K; i++) {
        cin >> rot[i].r >> rot[i].c >> rot[i].s;
        rot[i].idx = i; //인덱스
    }

    vector<vector<int>> tmp = matrix; //임시저장
    do {
        for (int i = 0; i < K; i++) { //회전
            for (int j = 1; j <= rot[i].s; j++) //각 회전 연산에 대해 rot[i].s개의 정사각형을 회전하게 됨
                rotate(rot[i].r - j - 1, rot[i].c - j - 1, //시작점
                       rot[i].r + j - 1, rot[i].c + j - 1); //끝점
        }
        result = min(result, calcArr(N, M)); //최솟값 갱신
        matrix = tmp; //복구
    } while (next_permutation(rot.begin(), rot.end(),
                              [](const info &i1, const info &i2) { //idx에 대해 순열
                                  return i1.idx < i2.idx;
                              }));
    cout << result;
}