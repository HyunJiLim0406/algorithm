#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<ll, ll> findPos(int cnt, string str, pair<ll, ll> pos) {
    if (cnt == str.size()) //끝까지 살펴보면 리턴
        return pos;
    //2를 곱해줌
    pos.first *= 2;
    pos.second *= 2;
    switch (str[cnt]) {
        case '1':
            return findPos(cnt + 1, str, make_pair(pos.first, pos.second + 1));
        case '2':
            return findPos(cnt + 1, str, pos);
        case '3':
            return findPos(cnt + 1, str, make_pair(pos.first + 1, pos.second));
        case '4':
            return findPos(cnt + 1, str, make_pair(pos.first + 1, pos.second + 1));
    }
}

string findStr(int cnt, string str, pair<ll, ll> pos, int d) {
    if (cnt == d) //끝까지 살펴보면 리턴
        return str;
    if (pos.first % 2 == 1 && pos.second % 2 == 1)
        str += "4";
    else if (pos.first % 2 == 1)
        str += "3";
    else if (pos.second % 2 == 1)
        str += "1";
    else
        str += "2";
    //2를 나눠줌
    pos.first /= 2;
    pos.second /= 2;
    return findStr(cnt + 1, str, pos, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    ll x, y;
    string input;

    cin >> d >> input >> x >> y;
    ll line = pow(2, d); //최대 좌표
    pair<ll, ll> pos = findPos(0, input, make_pair(0, 0)); //입력값의 좌표 찾기
    //목표값의 좌표
    pos.first -= y;
    pos.second += x;

    if (pos.first < 0 || pos.first >= line || pos.second < 0 || pos.second >= line) //범위 확인
        cout << -1;
    else {
        string res = findStr(0, "", pos, d);
        reverse(res.begin(), res.end()); //뒤집기
        cout << res;
    }
}