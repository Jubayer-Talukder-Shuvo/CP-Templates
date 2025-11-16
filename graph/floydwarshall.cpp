//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll INF = 1e15; // much bigger than any possible path
const int N = 530;
vector<vector<ll>> g(N, vector<ll>(N, INF));
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
 
    f(i, 1, n) g[i][i] = 0;
 
    f(i, 1, m) {
        int v1, v2;
        ll w;
        cin >> v1 >> v2 >> w;
        g[v1][v2] = min(g[v1][v2], w);
        g[v2][v1] = min(g[v2][v1], w);
    }
 
    f(k, 1, n)
        f(i, 1, n)
            f(j, 1, n)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (g[l][r] >= INF) cout << -1 << "\n";
        else cout << g[l][r] << "\n";
    }
}
 
int main() {
    fastio;
    solve();
    return 0;
}