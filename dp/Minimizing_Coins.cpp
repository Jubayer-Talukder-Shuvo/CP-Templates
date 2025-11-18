//given array of size n consisting of available coins, find out minimum number of coins needed to build x coins


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
const int N = 1000010;

// int n, x;
// vi a(110);
// vll dp(N, -1);


// ll solverX(int x){
//     if(x==0) return 0;
//     if(dp[x]!=-1) return dp[x];

//     ll ans=INT_MAX;

//     f(i, 1, n){
//         if(x-a[i]>=0) ans=min(ans, 1+solverX(x-a[i]));
//     }

//     return dp[x]=ans;
// }


// void solve(){
//     cin>>n>>x;

//     f(i, 1, n) cin>>a[i];

//     ll ans=solverX(x);

//     if(ans==INT_MAX) cout<<-1<<endl;
//     else cout<<ans<<endl;
// }

// int main(){
//     fastio;
//     solve();
//     return 0;
// }

void solve(){
    int n, x;
    cin>>n>>x;
    vi a(n+1);
    f(i, 1, n) cin>>a[i];

    vll dp(x+100, INT_MAX);
    dp[0]=0;



    f(i, 1, x){
        f(j, 1, n){
            if(i-a[j]>=0 && dp[i-a[j]]!=INT_MAX) dp[i]=min(dp[i], dp[i-a[j]]+1);
        }
    }





    cout<<((dp[x]==INT_MAX)? -1 : dp[x])<<endl;
}



int main(){
    solve();
}