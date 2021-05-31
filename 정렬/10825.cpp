#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct info {
    string name;
    int kor, eng, math;
};

bool cmp(const info &s1, const info &s2) {
    if (s1.kor == s2.kor && s1.eng == s2.eng && s1.math == s2.math)
        return s1.name < s2.name;
    if (s1.kor == s2.kor && s1.eng == s2.eng)
        return s1.math > s2.math;
    if (s1.kor == s2.kor)
        return s1.eng < s2.eng;
    return s1.kor > s2.kor;
}

int main() {
    int N, k, e, m;
    string n;
    vector<info> student;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n >> k >> e >> m;
        student.push_back({n, k, e, m});
    }
    sort(student.begin(), student.end(), cmp);
    for (int i = 0; i < N; i++)
        cout << student[i].name << '\n';
}