#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> pi;

void generatePi(string p) {
    pi.assign(p.size(), 0);
    int p_idx = 0;
    for (int i = 1; i < p.size(); i++) {
        while (p_idx > 0 && p[i] != p[p_idx]) //일치할 때까지 이동
            p_idx = pi[p_idx - 1];
        if (p[i] == p[p_idx]) //일치하면 pi에 저장
            pi[i] = ++p_idx;
    }
}

vector<int> kmp(string t, string p) {
    vector<int> result;
    int p_idx = 0;
    for (int i = 0; i < t.size(); i++) {
        while (p_idx > 0 && t[i] != p[p_idx]) //일치할 때까지 이동
            p_idx = pi[p_idx - 1];
        if (t[i] != p[p_idx])
            continue;
        if (p_idx == p.size() - 1) { //끝까지 확인
            result.push_back(i - p.size() + 2);
            p_idx = pi[p_idx]; //커서 이동
        } else
            p_idx++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;

    getline(cin, t);
    getline(cin, p);
    generatePi(p); //pi 배열 만들기
    vector<int> res = kmp(t, p);
    cout << res.size() << '\n';
    for (int re : res)
        cout << re << ' ';
}