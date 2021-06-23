#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int N, max_cnt = 0;
    string input;
    map<string, int> m;
    set<string> result;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        m[input]++;
    }
    for (auto iter : m) {
        if (iter.second == max_cnt) //최댓값과 같을 때
            result.insert(iter.first);
        else if (iter.second > max_cnt) { //새로운 최댓값
            result.clear();
            max_cnt = iter.second;
            result.insert(iter.first);
        }
    }
    cout << *result.begin(); //첫번째 원소
}