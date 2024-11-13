#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, M;

const int dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
const char dir [] = {'D', 'R', 'U', 'L'};

int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char> (M));
    vector<vector<bool>> visited(N, vector<bool> (M));
    
    pair<int, int> start, end;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            else if (arr[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }

    queue<pair<int, int>> bfsQueue;
    map<pair<int, int>, string> mapPaths;
    mapPaths[start] = "";
    bfsQueue.push(start);
    arr[start.first][start.second] = '#';
    while (bfsQueue.size()) {
        pair<int, int> p = bfsQueue.front();
        bfsQueue.pop();
        if (p.first == end.first && p.second == end.second) {
            cout << "YES\n" << mapPaths[p].length() << "\n";
            cout << mapPaths[p] << "\n";
            return 0;
        }

        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M) continue;
            if (arr[x + dx[i]][y + dy[i]] == '#') continue;
            arr[x + dx[i]][y + dy[i]] = '#';
            pair<int, int> nextP;
            nextP.first = x + dx[i];
            nextP.second = y + dy[i];
            mapPaths[nextP] = mapPaths[p] + dir[i];
            bfsQueue.push(nextP);
        }

        mapPaths.erase(p);
    }

    cout << "NO\n";


    return 0;
}
