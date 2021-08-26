#include <iostream>
#include <vector>

using namespace std;

vector<int> tri_num;

void init() {
    int num = 1;
    while (true) {
        int tri = num * (num + 1) / 2;
        if (tri > 1000)
            break;
        tri_num.push_back(tri);
        num++;
    }
}

bool isThree(int num) {
    for (int i = 0; i < tri_num.size(); i++) {
        for (int j = 0; j < tri_num.size(); j++) {
            for (int k = 0; k < tri_num.size(); k++) {
                if (tri_num[i] + tri_num[j] + tri_num[k] == num)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    int T, K;

    init();
    cin >> T;
    while (T--) {
        cin >> K;
        cout << ((isThree(K)) ? 1 : 0) << '\n';
    }
}