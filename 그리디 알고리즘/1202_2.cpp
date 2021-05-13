#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    vector<int> bag;
    vector<pair<int, int>> gem;
    int N, K, M, V;

    cin >> N >> K;
    gem.assign(N, make_pair(0, 0));
    bag.assign(K, 0);
    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        gem[i] = make_pair(M, V);
    }
    for (int i = 0; i < K; i++)
        cin >> bag[i];
    sort(gem.begin(), gem.end()); //무게 순서로 정렬
    sort(bag.begin(), bag.end()); //무게 순서로 정렬

    long long result = 0;
    int gem_idx = 0; //모든 보석 한번씩만 확인
    for (int i = 0; i < K; i++) {
        while ((gem_idx < N) && (gem[gem_idx].first <= bag[i])) //가방에 넣을 수 있는 보석이라면 우선순위 큐에 삽입
            pq.push(gem[gem_idx++].second);
        if (!pq.empty()) { //가방 하나에 대해 가장 가치가 큰 보석 하나만 pop
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}