#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmpString(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if ((b[i]!='?') && (b[i] != a[i])) //?가 아닌데 a[i]와 다름
            return false;
    }
    return true;
}

int main() {
    int M, N, Q;
    vector<string> v;
    string input;

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> input;
        v.push_back(input);
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int cnt = 0;
        cin >> input;
        for (int j = 0; j < M; j++) {
            if (cmpString(v[j], input))
                cnt++;
        }
        cout << cnt << '\n';
    }
}