#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, M;
int dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};

void dfs (int x, int y, vector<vector<int>>& arr) {
    arr[x][y] = true;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M) continue;
        if (!arr[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i], arr);
    }
}


int main () {
//    cin.tie(0);
//    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    
    vector<vector<int>> arr(N, vector<int> (M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '#') arr[i][j] = true;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!arr[i][j]) {
                ans++;
                dfs(i, j, arr);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
