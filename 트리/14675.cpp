#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, q, t, k;

    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    while (--n) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> q;
    while (q--) {
        cin >> t >> k;
        if (t == 1 && graph[k].size() == 1) //leaf node
            cout << "no\n";
        else //간선은 무조건 단절선, leaf node가 아닌 정점
            cout << "yes\n";
    }
}