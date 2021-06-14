#include <iostream>

using namespace std;

int main() {
    int L, P, V, t = 1;

    while (true) {
        cin >> L >> P >> V;
        if (!L && !P && !V)
            break;
        int day = (V / P) * L;
        day += min(V % P, L);
        cout << "Case " << t << ": " << day << '\n';
        t++;
    }
}