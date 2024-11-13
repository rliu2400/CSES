#include <bits/stdc++.h>
using namespace std;
 
//constants
#define mod 1e9+7 // 998244353
#define pi 3.1415926535897932384626433832795
 
//for loops
#define for0(i, N) for (int i = 0; i < (int) N; i++)
#define for1(i, N) for (int i = 1; i <= (int) N; i++)
#define forr0(i, N) for (int i = (int) N - 1; ~i; i--)
#define forr1(i, N) for (int i = (int) N; i; i--)
#define foru(i, l, r, x) for (int i = l; i <= r; i += x)
 
//primitives & string
using ll = long long;
using str = std::string;
 
//pairs
using ii = std::pair<int, int>;
using llll = std::pair<ll, ll>;
#define mp make_pair
#define fi first
#define se second
using mii = std::map<int, int>;
using mllll = std::map<ll, ll>;
 
//vectors
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vii = std::vector<ii>;
using vs = std::vector<str>;
using vb = std::vector<bool>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vb = std::vector<bool>;
 
//shortcuts
#define sz(x) int((x).size())
#define bg(x) x.begin()
//      end(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
 
#define lb lower_bound
#define ub upper_bound
 
//those grid problems (thanks BenCh)
const int dx[4]{1, 0, -1, 0},  dy[4]{0, 1, 0, -1};
 
//ceiling and floor divsion
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); }
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }
 
//ACTUAL CODE
//------------------------------------------------------------------------------
//                                                                             |
//                                                                             |


signed main () {
    cin.tie(0); ios::sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<llll>> neighbors(N);
    vll dist(N, __LONG_LONG_MAX__);
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        neighbors[a-1].pb(mp(c, b-1));
    }
    
    using T = pair<ll, ll>;
    priority_queue<T, vector<T>, greater<T>> pq;

    int start = 0;
    dist[start] = 0;
    pq.push(mp(0, start));

    while (!pq.empty()) {
        const auto [cdist, node] = pq.top();
        pq.pop();
        if (cdist != dist[node]) {
            continue;
        }
        for (const llll &i : neighbors[node]) {
            if (cdist + i.first < dist[i.second]) {
                pq.push(mp(dist[i.second] = cdist + i.first, i.second));
            }
        }
    }

    for (int i = 0; i < N - 1; i++) {
        cout << dist[i] << " ";
    }
    cout << dist[N - 1] << endl;
}


//                                                                             |
//                                                                             |
//------------------------------------------------------------------------------
 
 
/* stuff you should look for
	* int overflow, array out of bounds
	* special cases (n=1, n = 0?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
    * don't be mental diffed
*/
