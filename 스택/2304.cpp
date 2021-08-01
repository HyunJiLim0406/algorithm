#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, result = 0;
    stack<pair<int, int>> s;

    cin >> N;
    vector<pair<int, int>> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i].first >> input[i].second;
    sort(input.begin(), input.end()); //정렬
    for (int i = 0; i < N; i++) {
        pair<int, int> info;
        while (!s.empty() && s.top().second < input[i].second) { //이번 기둥보다 작은 기둥 스택에서 빼기
            info = s.top();
            s.pop();
        }
        if (s.empty() && i > 0) //스택이 전부 비게 되면(이번 기둥이 지금까지 중 가장 큰 기둥이었다면) 넓이 계산
            result += (input[i].first - info.first) * info.second;
        s.push(input[i]); //이번 기둥 스택에 넣기
    }
    while (s.size() > 1) { //스택에 남아있는 기둥 계산
        pair<int, int> info = s.top();
        s.pop();
        result += (info.first - s.top().first) * info.second;
    }
    result += s.top().second; //마지막 기둥
    cout << result;
}