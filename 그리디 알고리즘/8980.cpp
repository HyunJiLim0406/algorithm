#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct info {
    int s, d, w;
};

int maxWeight(vector<int> &capacity, int start, int end, int weight) {
    int result = weight; //상자 자체의 무게
    for (int i = start; i <= end; i++) //이동 구간의 용량과 비교해서 최솟값 리턴
        result = min(result, capacity[i]);
    return result;
}

void reduceCapacity(vector<int> &capacity, int start, int end, int weight) {
    for (int i = start; i <= end; i++) //해당 박스를 실어야 하는 구간의 용량 줄이기
        capacity[i] -= weight;
}

int main() {
    int n, c, m;

    cin >> n >> c >> m;
    vector<info> box(m);
    for (int i = 0; i < m; i++)
        cin >> box[i].s >> box[i].d >> box[i].w;
    sort(box.begin(), box.end(),
         [](const info &i1, const info &i2) {
             if (i1.d != i2.d)
                 return i1.d < i2.d;
             return i1.s < i2.s;
         });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> capacity(n + 1); //각 마을별 적재할 수 있는 용량
    capacity[0] = c;
    int result = 0, idx = 0;
    for (int i = 1; i <= n; i++) {
        capacity[i] = capacity[i - 1]; //이전 마을의 용량을 그대로 가져옴
        while (!pq.empty() && i >= pq.top().first) { //내릴 수 있는 상자 내리기
            result += pq.top().second;
            capacity[pq.top().first] += pq.top().second; //용량 증가
            pq.pop();
        }
        while (idx < m && box[idx].s <= i) { //실을 수 있는 모든 상자에 대해
            int weight = maxWeight(capacity, box[idx].s, i, box[idx].w); //올릴 수 있는 최대무게
            if (weight != 0) { //실을 수 있다면
                reduceCapacity(capacity, box[idx].s, i, weight); //구간의 용량 줄이기
                pq.push(make_pair(box[idx].d, weight)); //우선순위 큐에 삽입
            }
            idx++;
        }
    }
    cout << result;
}