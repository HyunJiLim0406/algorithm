#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dist;

void floydWarshall(int N) { //플로이드-워셜
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
        }
    }
}

int scoring(int idx, int N) { //각 후보의 점수
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (i == idx)
            continue;
        result = max(result, dist[idx][i]);
    }
    return result;
}

int main() {
    int N, a, b;

    cin >> N;
    dist.assign(N + 1, vector<int>(N + 1, N + 1));
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    floydWarshall(N);
    int score = N + 1;
    vector<int> candi;
    for (int i = 1; i <= N; i++) {
        int tmp = scoring(i, N);
        if (tmp < score) { //점수 초기화
            score = tmp;
            candi.clear();
        }
        if (tmp == score) //후보 추가
            candi.push_back(i);
    }
    cout << score << ' ' << candi.size() << '\n';
    for (auto c : candi)
        cout << c << ' ';
}