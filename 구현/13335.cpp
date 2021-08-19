#include <iostream>
#include <vector>

using namespace std;

vector<int> truck, pos;

int moveTruck(int n, int w) {
    int result = 0;
    for (int i = 0; i < n; i++) { //다리 위에 있는 트럭만 이동
        if (pos[i] == -1 || pos[i] == w)
            continue;
        pos[i]++;
        if (pos[i] == w) //끝에 도달하면 다리의 무게 줄여줌
            result += truck[i];
    }
    return result;
}

int main() {
    int n, w, L;

    cin >> n >> w >> L;
    truck.assign(n, 0);
    pos.assign(n, -1);
    for (int i = 0; i < n; i++)
        cin >> truck[i];
    int idx = 0, weight = 0, result = 0;
    while (pos[n - 1] != w) { //마지막 트럭이 도착할 때까지
        weight -= moveTruck(n, w);
        if (idx < n && weight + truck[idx] <= L) { //새로운 트럭이 올라갈 수 있다면
            weight += truck[idx];
            pos[idx++] = 0;
        }
        result++;
    }
    cout << result;
}