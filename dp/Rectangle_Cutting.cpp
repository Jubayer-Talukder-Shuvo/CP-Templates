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
const int N=505;
int dp[N][N];
 
 
int solverX(int a, int b){
    if(a==b) return 0;
    if(a<b) swap(a, b);
 
    if(dp[a][b]!=-1) return dp[a][b];
    // cout<<a-b<<" "<<b<<endl;
    // cout<<b<<' '<<b<<endl;
    int ans=1+solverX(a-b, b)+solverX(b, b);

    return dp[a][b]=ans;
 
}
 
 
void solve(){
    int a, b;
    cin>>a>>b;
 
    if(a<b) swap(a, b);
    cout<<solverX(a, b)<<endl;
 
}
 
int main(){
    fastio;
    memset(dp, -1, sizeof(dp));
    solve();
    return 0;
}