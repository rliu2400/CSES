#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<ll> ps(N + 1);
    for (int i = 0; i < N; i++) ps[i + 1] = arr[i] + ps[i];

    ll min_seen = 0, ans = arr[0];
    for (int i = 1; i <= N; i++) {
        ans = max(ans, ps[i] - min_seen);
        min_seen = min(min_seen, ps[i]);
    }

    cout << ans << "\n";

    return 0;
}
