#include <iostream>
using namespace std;

int main() {
    int line[3], z, z_index, sum;

    while (true) {
        sum = 0;
        z = 0;
        for (int i = 0; i < 3; i++) {
            cin >> line[i];
            if (line[i] > z) { //제일 긴 변 저장
                z = line[i];
                z_index = i;
            }
        }
        if (line[0] == 0 && line[1] == 0 && line[2] == 0)
            break;
        for (int i = 0; i < 3; i++) {
            if (i != z_index) //나머지 변 제곱해서 더함
                sum += (line[i] * line[i]);
        }
        if (sum == (z * z))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
}