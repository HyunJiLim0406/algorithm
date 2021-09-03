#include <iostream>

using namespace std;

pair<int, int> diet(int W, int Io, int T, int D, int I, int A, bool flag) {
    while (D--) {
        int change = I - (Io + A); //변화량
        W += change;
        if (flag && abs(change) > T) //일일 기초 대사량 변화 반영
            Io += (change % 2 == -1) ? change / 2 - 1 : change / 2; // -5/2=-3이 나오도록
        if (W <= 0 || Io <= 0) //체중이 0g 이하거나 일일 기초 대사량이 0Kcal 이하인 경우
            return make_pair(-1, -1);
    }
    return make_pair(W, Io);
}

int main() {
    int W, Io, T, D, I, A;
    pair<int, int> result;

    cin >> W >> Io >> T >> D >> I >> A;
    result = diet(W, Io, T, D, I, A, false);
    if (result.first == -1)
        cout << "Danger Diet\n";
    else
        cout << result.first << ' ' << result.second << '\n';

    result = diet(W, Io, T, D, I, A, true);
    if (result.first == -1)
        cout << "Danger Diet\n";
    else {
        cout << result.first << ' ' << result.second << ' ';
        if (result.second < Io) //변화한 일일 기초 대사량이 기존의 일일 기초 대사량보다 작다면 요요
            cout << "YOYO\n";
        else
            cout << "NO\n";
    }
}