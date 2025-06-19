#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi  vector<int>

//Number Theory
void sieve(int n) {
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;   

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {

            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }


    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

long long factorial(int n) {
    long long res=1;
    for (int i=2; i<=n; ++i) {
        res*=i;
    }
    return res;
}

bool isPrime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

int multiply(int n, int x){
    if(x==0) return 1;
    if(x==1) return n;
    int ans=n*n;
    int cnt=2;
    while(1){
        if(cnt*2 >= x){
            ans=ans*multiply(n, x-cnt);
            break;
        }
        ans*=ans;
        cnt*=2;
    }
    return ans;
}

int multiply_iterative(int n, int x) {
    int result=1;
    while(x>0) {
        if(x%2==1) result*=n;
        n*=n;
        x/=2;
    }
    return result;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long intLogFloor(long long a, long long n) {
    if (a<=1 || n<1) return 0;

    long long res=0, power=1;
    while (power<=n/a) {
        power*=a;
        res++;
    }
    return res;
}

long long intLogCeil(long long a, long long n) {
    if (a <= 1 || n < 1) return 0;

    long long res = 0, power = 1;
    while (power < n) {
        power *= a;
        res++;
    }
    return res;
}

long long intLogRound(long long a, long long n) {
    long long floorVal = intLogFloor(a, n);
    long long ceilVal = intLogCeil(a, n);

    // Compare distances between n and a^floorVal vs a^ceilVal
    long long lowDiff = n - pow(a, floorVal);
    long long highDiff = pow(a, ceilVal) - n;

    return (highDiff < lowDiff) ? ceilVal : floorVal;
}

vector<int> getFactors(int n) {
    vector<int> factors;
    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            factors.push_back(i);
            if(i!=n/i) factors.push_back(n/i);
        }
    }
    sort(factors.begin(), factors.end()); // Optional: sort in ascending order
    return factors;
}

//bit manipulation
void printBinary(ll num) {
    for (ll i = 31; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout<<endl;
}

//Others
void Kadanes(){
    int n;
    cin>>n;
    int a[n];
    f(i, 0, n-1) cin>>a[i];
    int maxSum=INT_MIN, curSum=0;
    int st=0, end=0, tempStart=0;

    f(i, 0, n-1){
        curSum+=a[i];
        if(curSum>maxSum){
            maxSum=curSum;
            st=tempStart;
            end=i;
        }
        if(curSum<0){
            curSum=0;
            tempStart=i+1;
        }
    }


    cout<<st<<" "<<end<<endl;
    cout<<maxSum<<endl;
}

bool isSortedIncreasing(int a[], int n){
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}

bool balanced_checker(string s){
    int b=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') b++;
        else b--;
        
        if(b<0) return false;
    }
    if(b) return false;
    return true;
}

int secondMinimum(const vector<int>& v) {
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : v) {
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2 && num > min1) {
            min2 = num;
        }
    }

    if (min2 == INT_MAX) return min1; 
    return min2;
}

void print_vect(const vector<int>& v){
    for(auto &i : v){
        cout << i << " ";
    }
    cout << endl;
}

bool isPalindrome(const vector<int>& v) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        if (v[l] != v[r])
            return false;
        l++;
        r--;
    }
    return true;
}

//binary search
int lower_bound_my(vector<int>& arr, int x) {
    int l=0, r=arr.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]<x){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}





// string s = "Hello World";
// size_t pos = s.find("World");
// if (pos != string::npos) {
//     cout << "Found at index: " << pos <<endl;  // Output: Found at index: 6
// }

int main(){
    test{
        int a,b;
        cin>>a>>b;
        cout<<multiply_iterative(a,b)<<endl;
    }
    return 0;
}
