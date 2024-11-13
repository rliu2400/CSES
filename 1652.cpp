#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> ps(N + 1, vector<int> (N + 1));

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < N; j++) {
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] + (S[j] == '*') - ps[i][j];
        }
    }

    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ps[x2][y2]  - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}
