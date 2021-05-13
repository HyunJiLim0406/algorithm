#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<pair<int, int>> pq;
    multiset<int> bag;
    multiset<int>::iterator iter;
    int N, K, M, V, C;

    cin >> N >> K;
    for (int i = 0; i < N; i++) { //가치가 큰 보석부터 나오도록 우선순위 큐에 삽입
        cin >> M >> V;
        pq.push(make_pair(V, M));
    }
    for (int i = 0; i < K; i++) { //가방 무게 오름차순 멀티셋에 삽입
        cin >> C;
        bag.insert(C);
    }
    long long result = 0;
    while (!pq.empty()) { //가장 비싼 보석부터
        int value = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        iter = bag.lower_bound(weight); //가장 잘맞는 무게의 가방 찾기
        if (iter != bag.end()) { //있으면 가방 지우고 result 증가
            bag.erase(iter);
            result += value;
        }
    }
    cout << result;
}