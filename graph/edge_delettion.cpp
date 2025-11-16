#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define edge(v) g[v].size()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;
const int N = 1e5 + 10;

vector<int> g[N];
vector<int> subtree_sum(N, 0);
vector<int> val(N, 0);

void dfs(int vertex, int par){


    subtree_sum[vertex]+=val[vertex];

    for(int child : g[v]){
        if(child==par) continue;

        dfs(child, vertex);

        subtree_sum[vertex]+=subtree_sum[child];

    }


}




void solve(){
    int n;
    cin>>n;


    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }

    f(i, 1, n) cin>>val[i];

    dfs(1);

    ll ans=0;

    for(int i=1; i<=n; i++){

        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(ans, (1LL*part1*part2)%M);

    }

}

int main(){
    fastio;
    solve();
    return 0;
}