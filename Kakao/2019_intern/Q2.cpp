#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> t;

bool cmp(const vector<int> &v1, const vector<int> &v2) { //2차원 벡터를 각 벡터의 길이 기준으로 정렬
    if (v1.size() < v2.size())
        return true;
    return false;
}

vector<int> findTuple() {
    vector<int> result;
    map<int, bool> m;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (!m[t[i][j]]) { //차집합에 해당하면 튜플의 원소
                m[t[i][j]] = true;
                result.push_back(t[i][j]);
            }
        }
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> tmp;
    string str = "";
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{')
            continue;
        else if (s[i] == '}') { //닫는 괄호면 숫자 tmp 벡터에 넣고 tmp 벡터를 t 벡터에 넣기
            tmp.push_back(stoi(str));
            t.push_back(tmp);
            tmp.clear();
            str.clear();
        } else if (s[i] == ',') { //쉼표면 괄호 내의 쉼표였는지 확인하고 숫자 tmp 벡터에 넣기
            if (str.size() > 0) {
                tmp.push_back(stoi(str));
                str.clear();
            }
        } else //숫자 string 형태로 쌓아두기
            str += s[i];
    }
    sort(t.begin(), t.end(), cmp); //길이 순으로 정렬
    vector<int> answer = findTuple();
    return answer;
}

int main() {
    vector<int> v;

    v = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    t.clear();

    v = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    t.clear();

    v = solution("{{20,111},{111}}");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    t.clear();

    v = solution("{{123}}");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    t.clear();

    v = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    t.clear();
}