//how many ways to construct n by throwing dice of 1 to 6

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
const int N = 1e6+10;
vll dp(N, -1);

ll solverX(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    ll ans=0;
    f(i, 1, 6) if(n-i>=0) ans=(ans+solverX(n-i))%M;
    return dp[n] = ans;
}




void solve(){
    int n;
    cin>>n;

    cout<<solverX(n)<<endl;

}

int main(){
    fastio;
    solve();
    return 0;
}


// void solve(){
//     int n;
//     cin>>n;

//     vll dp(N, 0);
//     dp[0]=1;
//     f(i, 1, n){
//         f(j, 1, 6){
//             if(i-j>=0) dp[i]=(dp[i]+dp[i-j])%M;
//         }
//     }


//     cout<<dp[n]<<endl;
// }


// int main(){
//     solve();
// }