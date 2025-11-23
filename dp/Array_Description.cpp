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



void solve(){
    int n, m;
    cin>>n>>m;

    vi a(n+1);
    f(i, 1, n) cin>>a[i];

    vv(dp, ll, n+1, m+1);


    if(a[1]==0){
        f(i, 1, m) dp[1][i]=1;
    }else{
        dp[1][a[1]]=1;
    }




    f(i, 2, n){

        f(j, 1, m){
            if(a[i]!=0 && a[i]!=j){
                dp[i][j]=0;
                continue;
            }

            dp[i][j]=dp[i-1][j];
            if(j-1>0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%M;
            if(j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%M;

        }

    }
    ll ans=0;
    f(i, 1, m) ans=(dp[n][i]+ans)%M;
    cout<<ans<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}




