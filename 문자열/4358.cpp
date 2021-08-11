#include <iostream>
#include <map>

using namespace std;

int main() {
    double cnt = 0;
    string input;
    map<string, double> m;

    while (getline(cin, input)) {
        m[input]++;
        cnt++;
    }
    cout << fixed;
    cout.precision(4);
    for (const auto &o:m)
        cout << o.first << ' ' << (o.second * 100.0) / cnt << '\n';
}