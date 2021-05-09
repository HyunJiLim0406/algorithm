#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, B;
vector<vector<int>> land;
int min_time = 1e9;

int mineLand(int height) {
    int blocks = B; //블럭 수
    int t = 0; //소요 시간

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (land[i][j] > height) { //땅을 깎아야 할 때
                blocks += (land[i][j] - height);
                t += 2 * (land[i][j] - height);
            } else if (land[i][j] < height) { //땅을 쌓아야 할 때, 당장 블럭 음수여도 나중에 채워질 수 있음
                blocks -= (height - land[i][j]);
                t += (height - land[i][j]);
            }
            if (t > min_time) //최솟값보다 크면 더 탐색하지 않음
                return -1;
        }
    }
    if (blocks < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return -1;
    return min_time = t; //최솟값 갱신
}

int main() {
    int min_height = 257, max_height = -1;
    cin >> N >> M >> B;
    land.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    int t, h;
    for (int i = min_height; i <= max_height; i++) {
        int result = mineLand(i); //모든 땅을 i 높이로 만들 때 걸리는 시간
        if (result != -1) { //-1이 아니면 최솟값이니 갱신
            h = i;
            t = result;
        }
    }
    cout << t << ' ' << h;
}