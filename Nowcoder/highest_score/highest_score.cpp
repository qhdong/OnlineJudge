#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> score(n, 0);
        for (int i = 0; i != n; ++i) cin >> score[i];

        // handle querys
        for (int i = 0; i != m; ++i) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'Q') {
                cout << *max_element(score.begin() + a - 1, score.begin() + b) << endl;
            } else if (c == 'U') {
                score[a-1] = b;
            }
        }
    }

    return 0;
}
