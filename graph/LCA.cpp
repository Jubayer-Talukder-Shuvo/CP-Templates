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
const int N = 1e5+10;
vector<int> g[N];
int par[N];

void dfs(int v, int p){

    par[v]=p;

    for(int &child : g[v]){
        if(child==p) continue;
        dfs(child, v);
    }

}

vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.pb(v);
        v=par[v];
    }
    reverse(all(ans));
    return ans;
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

    dfs(1, -1);

    int x, y;
    cin>>x>>y;


    vector<int> path_x=path(x);
    vector<int> path_y=path(y);

    int LCA=-1;
    
    f(i, 0, min(path_x.size(), path_y.size())-1){
        if(path_x[i]==path_y[i]) LCA=path_x[i];
        else break;
    }

    cout<<LCA<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}