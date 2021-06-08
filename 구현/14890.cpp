#include <iostream>
#include <vector>

using namespace std;

bool isPromise(vector<int> v, int size, int L) {
    vector<bool> installed(size, false); //경사로 설치 여부 확인
    for (int i = 0; i < size - 1; i++) {
        if (abs(v[i] - v[i + 1]) > 1) //높이 차이 2이상 -> 경사로 설치 불가
            return false;
        if (v[i] < v[i + 1]) { //오르막길 설치
            for (int j = i; j > i - L; j--) { //경사로 설치
                if ((v[j] != v[i]) || (j < 0) || installed[j]) //평평한 길이 충분하지 않거나 경사로가 이미 설치 됐다면
                    return false;
            }
        } else if (v[i] > v[i + 1]) { //내리막길 설치
            for (int j = i + 1; j <= i + L; j++) { //경사로 설치
                if ((v[j] != v[i + 1]) || (j == size)) //평평한 길이 충분하지 않으면
                    return false;
                installed[j] = true;
            }
        }
    }
    return true; //갈 수 있는 길
}

int main() {
    int N, L;

    cin >> N >> L;
    vector<vector<int>> roads(2 * N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> roads[i][j]; //가로 길
            roads[j + N][i] = roads[i][j]; //세로 길
        }
    }
    int result = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (isPromise(roads[i], N, L)) //지나갈 수 있는 길인지 확인
            result++;
    }
    cout << result;
}