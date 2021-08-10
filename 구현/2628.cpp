#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int r, c, n, a, b, result = 0;
    vector<int> rows, cols;
    rows.push_back(0);
    cols.push_back(0);

    cin >> c >> r >> n;
    rows.push_back(r);
    cols.push_back(c);
    while (n--) {
        cin >> a >> b;
        if (a == 0)
            rows.push_back(b);
        if (a == 1)
            cols.push_back(b);
    }
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    for (int i = 1; i < rows.size(); i++) {
        for (int j = 1; j < cols.size(); j++)
            result = max(result, (rows[i] - rows[i - 1]) * (cols[j] - cols[j - 1]));
    }
    cout<<result;
}