#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> switches;

void maleSwitch(int num) {
    for (int i = 0; i < N; i++) {
        if ((i + 1) % num == 0)
            switches[i] = !switches[i];
    }
}

void femaleSwitch(int num) {
    int l = num - 1, r = num + 1;
    switches[num] = !switches[num];
    while (l >= 0 && r < N && switches[l] == switches[r]) {
        switches[l] = !switches[l];
        switches[r] = !switches[r];
        l--;
        r++;
    }
}

int main() {
    int n, input, s, num;

    cin >> N;
    switches.assign(N, false);
    for (int i = 0; i < N; i++) {
        cin >> input;
        switches[i] = (input) != 0;
    }
    cin >> n;
    while (n--) {
        cin >> s >> num;
        if (s == 1)
            maleSwitch(num);
        else
            femaleSwitch(num - 1);
    }
    for (int i = 1; i <= N; i++) {
        cout << switches[i - 1] << ' ';
        if(i%20==0)
            cout<<'\n';
    }
}