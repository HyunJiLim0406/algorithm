#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> check;

bool floydWarshall(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == j || i == k)
                    continue;
                if (graph[j][k] == graph[j][i] + graph[i][k]) //필요없는 간선
                    check[j][k] = true;
                else if (graph[j][k] > graph[j][i] + graph[i][k]) //주어진 입력이 최솟값이 아닐 때
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int N;

    cin >> N;
    graph.assign(N, vector<int>(N));
    check.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }
    bool pos = floydWarshall(N);
    if (!pos) {
        cout << -1;
        return 0;
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!check[i][j]) //지워지지 않은 간선 계산
                result += graph[i][j];
        }
    }
    cout << result / 2; //양방향이니 2로 나눠줌
}